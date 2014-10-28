#include "platform_array.h"
#include<string.h>
#include<fstream>



platform_array::platform_array(char *img_file, char *level_file)
  : image_array()
{
  ifstream level(level_file);
  int i, n, x, y;
  image * p;

  if ( ! level.is_open() )
  {
    cerr<<"could not open "<<level_file<<endl;
    exit(1);
  }

  level>>n;

  for ( i = 0; i < n; i ++ )
  {
    level>>x;
    level>>y;

    p = new image(img_file);
    assert(p);

    p->set_xy(x,y,0);
    add(p);
  }
  
  
}

platform_array::~platform_array()
{
}
