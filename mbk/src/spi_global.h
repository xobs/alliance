typedef struct spimodel {
  struct spimodel *NEXT;
  char            *MODEL;
  char             TYPE;
}spimodel ;

void spiloadmodel __P(( void ));
char spitranstype __P(( char* ));
char* spitransmodel __P(( char ));

/* Valeur pour dire que le nom de modele de transistor pass� � la fonction
 * spitranstype n'est pas d�fini. Ce nombre doit �tre une valeur impossible
 * pour le champs type des transistors */
#define SPI_UNK_TRANS_TYPE 64
