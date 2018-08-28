
// This file is part of the Alliance Project.
// Copyright (C) Laboratoire LIP6 - Departement ASIM
// Universite Pierre et Marie Curie
//
// The Alliance Project  is free software;  you can  redistribute it and/or
// modify  it  under the  terms  of  the  GNU  General  Public License  as
// published by  the Free  Software Foundation; either  version 2  of  the
// License, or (at your option) any later version.
// 
// The Alliance Project  is distributed in the hope that it will be useful,
// but  WITHOUT  ANY  WARRANTY;  without  even  the  implied  warranty  of
// MERCHANTABILITY  or  FITNESS  FOR A  PARTICULAR PURPOSE.   See  the GNU
// General Public License for more details.
// 
// You should have received a copy  of  the  GNU  General  Public  License
// along with  the Alliance Project;  if  not,  write to the  Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
//
//
// License-Tag
//
// Date   : 29/01/2004
// Author : Christophe Alexandre  <Christophe.Alexandre@lip6.fr>
//
// Authors-Tag 
#ifndef __PDETTOPLACEINS_H
#define __PDETTOPLACEINS_H

#include "PIns.h"

class PToPlaceIns;
class PDetSubRow;

class PDetToPlaceIns : public PIns {
    
  private:  
    PDetSubRow*	_subRow;
    PPos		_pos;
    double		_marginWidth;
    PPos		_leftCorner;
    bool		_placed;
  
  public:
    PDetToPlaceIns(PToPlaceIns* toplaceins);
    ~PDetToPlaceIns() {}

    PPos		GetPos() const				{ return _pos; }
    double		GetHeight() const;
    bool		GetOrientation() const;
    void		SetMarginWidth(const double mwidth)	{ _marginWidth = mwidth; }
    double		GetMarginWidth() const			{ return _marginWidth; }
    void		SetLeftCornerX(const double x);
    double		GetLeftCornerX() const			{ return _leftCorner.GetX(); }
    void		SetSubRow(PDetSubRow* subrow)		{ _subRow = subrow; }
    void		AddWhiteSpace()				{ ++_marginWidth; }
    void		AddDoubleWhiteSpace()			{ _marginWidth += 2; }
    void		UnPlace()				{ _placed = false; }
    void		Place()					{ _placed = true; }
    bool		IsPlaced() const			{ return _placed; }
    double		InitCost(const unsigned BBoxFlag, const unsigned CostFlag, const unsigned SaveFlag);
    double		DetPlaceUpdateCost();
    double		CurrentCost(const unsigned costflag);
    
    ostream&	Print(ostream& os) const;
    
    void	Save(struct phfig *physicalfig, const double dx, const double dy) const;

};
#endif /* __PDETTOPLACEINS_H */
