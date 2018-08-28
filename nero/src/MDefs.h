
// -*- C++ -*-
//
// $Id: MDefs.h,v 1.9 2008/06/11 09:20:34 jpc Exp $
//
// +-----------------------------------------------------------------+ 
// |        A l l i a n c e   C A D   S y s t e m                    |
// |              S i m p l e   R o u t e r                          |
// |                                                                 |
// |  Author      :                    Jean-Paul CHAPUT              |
// |  E-mail      :       alliance-support@asim.lip6.fr              |
// | =============================================================== |
// |  C++ Header  :       "./MDefs.h"                                |
// +-----------------------------------------------------------------+




# ifndef  __MDefs__
# define  __MDefs__  1


# include  "UDefs.h"
# include <limits.h>
# include <string.h>




// -------------------------------------------------------------------
// Class declarations.

  class CCoord;
  class CNode;
  class CNodeData;
  class CMatrixPri;
  class CMatrixNodes;
  class CDRGrid;
  class CNet;




// -------------------------------------------------------------------
// Module  :  "MDRGrid.cpp".


  // ---------------------------------------------------------------
  // Rectangle class.

  struct CRect {

    // Attributes.
    long x1;
    long y1;
    long x2;
    long y2;

    // Friend.
    friend ostream &operator<< (ostream &, const CRect *);

  };




  // ---------------------------------------------------------------
  // Bounding Box class.

  class CBB {

    // Attributes.
    public: int  x1;
    public: int  y1;
    public: int  x2;
    public: int  y2;
    public: int  hp;

    // Constructor.
    public: CBB (void);

    // Modifiers.
    public: void merge (CCoord &coord);

    // Friends.
    public: friend ostream &operator<< (ostream &o, CBB &self);
  };




  // ---------------------------------------------------------------
  // Coordinate class.

  class CCoord {

    public: int  x;
    public: int  y;
    public: int  z;

    // Constructors.
    public: CCoord (void)                { x = y = z = 0; }
    public: CCoord (int i, int j, int k) { x = i; y = j; z = k; }

    // Modifiers.
    public: CCoord &set (int i, int j, int k)
                        { x = i; y = j; z = k; return (*this); }

    // Friends.
    public: friend ostream &operator<< (ostream &o, CCoord &self) {
                     o << "(" << self.x
                       << "," << self.y
                       << "," << self.z << ")";

                     return (o);
                   }

  };




  // ---------------------------------------------------------------
  // Matrix iterator exception class.

  class e_matrix_iterator : public except_done {

    // Attributes.
    string  message;

    // Constructor.
    public: e_matrix_iterator (string msg) : message(msg) { }

    // Destructor.
    public: ~e_matrix_iterator (void) throw () { };

    // Overridables.
    public: const char* what () const throw () { return (message.c_str()); }

  };


  // ---------------------------------------------------------------
  // Too small zupper exception.

  class e_zupper : public except_done {

    // Attributes.
    public: int  zupper;

    // Constructor.
    public: e_zupper (int  zup) { zupper = zup; }

    // Destructor.
    public: ~e_zupper (void) throw () { };

    // Overridables.
    public: const char* what () const throw () {
              return ((char*)"\"zupper\" must not be lower than 4.");
            }
  };




  // ---------------------------------------------------------------
  // Detailed Routing Matrix Class.

  template<class __CNode__> class TMatrix {

    // Matrix hollow level class ---------------------------------

    public: struct _CHollow {

      typedef map<int, __CNode__*>  _CRow;
      typedef map<int, _CRow>       _CLayer;

      // Attributes.       
      public: _CLayer  nodes;

      // Destructor.
      ~_CHollow (void);

      // Modifier.
      public: __CNode__ &add (int x, int y);

      // Accessor.
      public: __CNode__ *get (int x, int y);

    };


    // Internal attributes.
    public: CDRGrid   *_drgrid;
    public: _CHollow   _zero;
    public: __CNode__ *_grid;
    public: __CNode__   hole;


    // Constructor.
    public: TMatrix  (CDRGrid *drgrid);
    private: TMatrix ( const TMatrix& );

    // Destructor.
    public: ~TMatrix (void);

    // Accessors.
    public: __CNode__ &operator[] (int index);

    // Modifiers.
    public: __CNode__ &add (int index);

  };


  // ---------------------------------------------------------------
  // Detailed Routing Grid Class.

  class CDRGrid {

    // Matrix common iterator class ------------------------------

    public: class iterator {

      // Attributes.
      public: int       _index;
      public: CDRGrid  *_drgrid;

      // Constructors.
      public: iterator (void);
      public: iterator (const iterator &other);

      // Accessors.
      public:         operator   int (void) { return ( _index ); }
      public:         operator   CCoord (void)
                                 { return ( CCoord (x(), y(), z()) ); }
      public: bool    operator== (iterator &other)
                                 { return (    (_drgrid == other._drgrid)
                                            && (_index  == other._index ) ); }

      // Accessors for matrix objects.
      public: char   &pri        (void);
      public: bool    isprihole  (void);
      public: CNode  &node       (void);
      public: CNode  &addnode    (void);
      public: bool    isnodehole (void);
      public: bool    take       (int pri);

      public: friend ostream &operator<< (ostream &o, iterator &self);

      public: void  valid     (bool validindex) throw (e_matrix_iterator);
      public:  int  x         (void) { return ( _drgrid->x (_index) ); }
      public:  int  y         (void) { return ( _drgrid->y (_index) ); }
      public:  int  z         (void) { return ( _drgrid->z (_index) ); }
      public: bool  outside   (void) { return ( _index == INT_MAX ); }
      public: bool  inside    (void) { return ( !outside() ); }
      public: bool  onAB      (void) { if (   (x() == 0)
                                           || (x() == _drgrid->X - 1) 
                                           || (y() == _drgrid->Y - 1) 
                                           || (y() == 0)) 
                                         return (true);

                                        return (false);
                                     };
      public:  int  manhattan (iterator &other) throw (e_matrix_iterator);
      public:  int  zupper    (void) { return ( _drgrid->zupper ); }

      // Modifiers.
      public: void      unlink (void)
                                 { _index = INT_MAX; _drgrid = NULL; }
      public: iterator &set    (int x, int y, int z);
      public: iterator &set    (CCoord &coord) 
                                 { return ( set(coord.x, coord.y, coord.z) ); }
      public: iterator &dx     (int d);
      public: iterator &dy     (int d);
      public: iterator &dz     (int d);
      public: iterator &left   (void) { return ( dx(-1) ); };
      public: iterator &right  (void) { return ( dx(+1) ); };
      public: iterator &down   (void) { return ( dy(-1) ); };
      public: iterator &up     (void) { return ( dy(+1) ); };
      public: iterator &bottom (void) { return ( dz(-1) ); };
      public: iterator &top    (void) { return ( dz(+1) ); };
      public: iterator &pnext  (void) { if (z() % 2)
                                          return ( right() );
                                        return ( up() );
                                      };
      public: iterator &pprev  (void) { if (z() % 2)
                                          return ( left() );
                                        return ( down() );
                                      };

    };


    // Matrix class ----------------------------------------------

    // Attributes.
    public: int xoffset;
    public: int yoffset;
    public: int X;
    public: int Y;
    public: int Z;
    public: int XY;
    public: int XYZ;
    public: int size;
    public: int zupper;
    public: int cost_x_hor;
    public: int cost_x_ver;
    public: int cost_y_hor;
    public: int cost_y_ver;
    public: int cost_z;

    public: iterator      origin;
    public: CMatrixPri   *pri;
    public: CMatrixNodes *nodes;

    // Constructor.
    public: CDRGrid  (int xoff, int yoff, int x, int y, int z, int zup) throw (e_zupper);
    private: CDRGrid ( const CDRGrid& );


    // Destructor.
    public: ~CDRGrid (void);

    // Modifiers.
    public: void  costs  (int x_hor, int x_ver, int y_hor, int y_ver, int z);

    // Utilities.
    public: int x  (int index) { return ( index       % X); }
    public: int y  (int index) { return ((index / X ) % Y); }
    public: int z  (int index) { return ((index / XY) % Z); }
    public: int dx (int index, int d);
    public: int dy (int index, int d);
    public: int dz (int index, int d);
    public: int id (int x, int y, int z)
                               { return ( x + (X * (y + (Y * z))) ); }

  };


  // ---------------------------------------------------------------
  // Detailed Routing Matrix Class (methods)


  template<class __CNode__>
  TMatrix<__CNode__>::_CHollow::~_CHollow (void)
  {
    typename   _CRow::iterator  itRow;
    typename _CLayer::iterator  itLayer;
  
  
    for (itLayer  = nodes.begin ();
         itLayer != nodes.end   (); itLayer++) {
      for (itRow  = itLayer->second.begin ();
           itRow != itLayer->second.end   (); itRow++) {
        delete itRow->second;
      }
    }
  }
  
  
  template<class __CNode__>
  __CNode__ &TMatrix<__CNode__>::_CHollow::add (int x, int y)
  {
    typename   _CRow::iterator  itRow;
    typename _CLayer::iterator  itLayer;
  
  
    itLayer = nodes.find (x);
    if (itLayer == nodes.end ()) { nodes[x] = _CRow (); }
  
    itRow = nodes[x].find (y);
    if (itRow == nodes[x].end ()) { nodes[x][y] = new __CNode__ (); }
  
    return (*(nodes[x][y]));
  }
  
  
  template<class __CNode__>
  __CNode__ *TMatrix<__CNode__>::_CHollow::get (int x, int y)
  {
    typename   _CRow::iterator  itRow;
    typename _CLayer::iterator  itLayer;
  
  
    itLayer = nodes.find (x);
    if (itLayer == nodes.end ()) { return (NULL); }
  
    itRow = nodes[x].find (y);
    if (itRow == nodes[x].end ()) { return (NULL); }
  
    return ((*itRow).second);
  }
  
  
  template<class __CNode__>
  TMatrix<__CNode__>::TMatrix (CDRGrid *drgrid)
    : _drgrid(drgrid)
    , hole   ()
  {
    _grid   = new __CNode__ [_drgrid->size];
  }
  
  
  template<class __CNode__>
  TMatrix<__CNode__>::~TMatrix (void)
  {
    delete [] _grid;
  }
  
  
  template<class __CNode__>
  __CNode__ &TMatrix<__CNode__>::operator[] (int index)
  {
    if (index < _drgrid->XY ) {
      __CNode__ *node = _zero.get (_drgrid->x(index), _drgrid->y(index)) ;
      if ( node != NULL ) return ( *node );
    } else {
      if (index < _drgrid->XYZ) return ( _grid[index - _drgrid->XY] );
    }
  
    return ( hole );
  }
  
  
  template<class __CNode__>
  __CNode__ &TMatrix<__CNode__>::add (int index)
  {
    if (index < _drgrid->XY) {
      return ( _zero.add (_drgrid->x(index), _drgrid->y(index)) );
    } else {
      if (index < _drgrid->XYZ) return ( (*this)[index] );
    }
  
    return ( hole );
  }




// -------------------------------------------------------------------
// Module  :  "MNodes.cpp".


  // ---------------------------------------------------------------
  // Node grabbing exception.

  class bad_grab : public except_done {

    // Attributes.
    public: int    x;
    public: int    y;
    public: int    z;
    public: string ownerName;
    public: string netName;
    public: int    pri;
    public: int    nodepri;
    public: bool   terminal;
    public: int    ident;

    // Constructor.
    public: bad_grab ( string owner
                     , string net
                     , int i
                     , int j
                     , int k
                     , int p
                     , int np
                     , bool term
                     , int id
                     )
              : x        (i)
              , y        (j)
              , z        (k)
              , ownerName(owner)
              , netName  (net)
              , pri      (p)
              , nodepri  (np)
              , terminal (term)
              , ident    (id)
              { }

    // Destructor.
    public: ~bad_grab (void) throw () { };

    // Overridables.
    public: const char* what () const throw () {
              return ((char*)"Attempt to grab a non-free node.");
            }

  };




  // ---------------------------------------------------------------
  // Node data class.

  class CNodeData {

    // Attributes.
    public: int    pri;
    public: CNet  *owner;
    public: CNode *rtree;
    public: int    ident;
    public: bool   obstacle;
    public: bool   lock;

    // Constructor.
    CNodeData (void);

  };




  // ---------------------------------------------------------------
  // Node class.

  class CNode {

    // Attributes.
    public: CNodeData  data;
    public: void      *algo;

    // Constructor.
    CNode ();

    // Modifiers.
    public: inline int  setid  (int id) { return (data.ident = id + 1); }
    public:        void grab   ( CNet *net
                               , int pri
                               , CDRGrid::iterator &coord
                               ) throw (bad_grab);
    public:        void ungrab (void);
    public:        void lock   (void)   { data.lock = true; }
    public:        void unlock (void)   { data.lock = false; }

    // Accessors.
    public: inline int  getid    (void) { return (data.ident - 1); }
    public: inline bool terminal (void) { return (data.ident != 0); }
    public: inline bool locked   (void) { return (data.lock); }
    public:        bool check    (bool cleared);

  };




  // ---------------------------------------------------------------
  // Matrix Node class (derived from TMatrix template).

  class CMatrixNodes : public TMatrix<CNode> {

    // Constructor.
    public: CMatrixNodes (CDRGrid *drgrid) : TMatrix<CNode>(drgrid) { }

    // Modifiers.
    public: void  obstacle (CRect &rect, int z);
    public: void  check    (bool cleared);

  };




// -------------------------------------------------------------------
// Module  :  "MPri.cpp".


  // ---------------------------------------------------------------
  // Matrix Priority class (derived from TMatrix template).

  class CMatrixPri : public TMatrix<char> {

    // Internal attributes.
    protected: CBB   _bb;

    // Attributes.
    public: int   offset;
    public: int   delta;
    public: bool  cleared;


    // Constructor.
    public: CMatrixPri (CDRGrid *drgrid)
      : TMatrix<char>(drgrid)
      , offset       (0)
      , delta        (0)
      , cleared      (false)
    { }

    // Modifiers.
    public: void clear       (void);
    public: void load        (CNet &net, bool global, int expand=0);
    public: bool take        (int pri, int index);
    public: void findfree    (int index, CNet &net);

    // Internal methods.
    private: char  nextPri (char curpri);

    // Friends.
    public: friend ostream &operator<< (ostream &o, CMatrixPri &self);

  };




// -------------------------------------------------------------------
// Module  :  "MNet.cpp".


  // ---------------------------------------------------------------
  // Duplicate terminal node exception.

  class dup_term : public except_done {

    // Attributes.
    public: string             name;
    public: CDRGrid::iterator  node;

    // Constructor.
    public: dup_term (string termName, CDRGrid::iterator &dupNode)
              : name(termName)
              , node(dupNode)
            { }

    // Destructor.
    public: ~dup_term (void) throw () { };

    // Overridables.
    public: const char* what () const throw () {
              return ((char*)"Duplicated terminal node.");
            }
  };




  // ---------------------------------------------------------------
  // Terminal merging exception.

  class merge_term : public except_done {

    // Attributes.
            string  message;
    public: int     id;

    // Constructor.
    public: merge_term ( int ident
                       , string& tn1
                       , string& tn2
                       , string& nn
                       , long x
                       , long y
                       , long z
                       )
              : message()
              , id     (ident)
            {
              ostringstream m;
              m << "Terminals \"" << tn1 << "\" and \"" << tn2 << "\" of net \"" << nn 
                << "\" overlaps at " << "(" << x << "," << y << "," << z << ")";
              message = m.str();
            }

    // Destructor.
    public: ~merge_term (void) throw () { };

    // Overridables.
    public: const char* what () const throw () {
              return (message.c_str());
            }
  };




  // ---------------------------------------------------------------
  // Terminal class.

  class CTerm {

    // Attributes.
    public: int                      id;
    public: string                   name;
    public: list<CDRGrid::iterator>  nodes;
    public: list<CRect>              rects;

    // Constructor.
    public: CTerm (string termName, int ident);

    // Destructor.
    public: ~CTerm (void);

    // Accessors.
    public: int                distance (CTerm &other);
    public: CTerm             &nearest  (CTerm &term1, CTerm &term2);
    public: CDRGrid::iterator &lowest   (void);

    // Modifiers.
    public: CNode *newaccess (int x, int y, int z, int ident, CNet *net)
                     throw (dup_term, bad_grab, merge_term);
    public: void   newaccess (CRect &rect, int z, int ident, CNet *net);
    public: void   merge     (CTerm *other, int ident, CNet *net);
    public: void   lockalone (bool global=false);
    public: void   setid     (int ident);

    // Friends.
    public: friend ostream &operator<< (ostream &o, CTerm &self);

  };




  // ---------------------------------------------------------------
  // Duplicate net exception.

  class dup_net : public except_done {

    // Attributes.
    public: string  name;

    // Constructor.
    public: dup_net (string netName) : name(netName) { }

    // Destructor.
    public: ~dup_net (void) throw () { };

    // Overridables.
    public: const char* what () const throw () {
              return ((char*)"Duplicated net.");
            }
  };




  // ---------------------------------------------------------------
  // Unknown terminal exception.

  class term_unknown : public except_done {

    // Attributes.
    public: string  netName;
    public: string  termName;

    // Constructor.
    public: term_unknown (string nName, string tName) : netName(nName), termName(tName) { }

    // Destructor.
    public: ~term_unknown (void) throw () { };

    // Overridables.
    public: virtual const char* what () const throw () {
              return ((char*)"Unknown terminal.");
            }
  };




  // ---------------------------------------------------------------
  // Net class.

  class CNet {

    // Attributes.
    public: int            pri;
    public: string         name;
    public: vector<CTerm*> terms;
    public: CNode*         rtree;
    public: CBB            bb;
    public: int            size;
    public: bool           external;
    public: bool           fixed;
    public: CDRGrid       *_drgrid;

    // Constructor.
    public: CNet (CDRGrid *drgrid, string netName="noname");

    // Destructor.
    public: ~CNet (void);

    // Operator.
    public: bool operator< (CNet &other);

    // Accessor.
    public: bool global (bool rglobal);

    // Modifiers.
    public: void newaccess (string termName, int x, int y, int z);
    public: void newaccess (string termName, CRect &rect, int z);
    public: void order     (void);
    public: void lockalone (bool rglobal);
    public: void locktree  (void);
    public: void unroute   (void);

    // Friends.
    public: friend ostream &print      (ostream &o, CNet *self);
    public: friend ostream &operator<< (ostream &o, CNet *self);

  };

  typedef  map<string, CNet*>  MNet;




// -------------------------------------------------------------------
// Module  :  "MMBK.h".


# include  "MMBK.h"




#endif
