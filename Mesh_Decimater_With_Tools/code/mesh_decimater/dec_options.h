#ifndef DEC_OPTIONS_H
#define DEC_OPTIONS_H

#include <string>
#include "CmdOption.h"

struct DecOptions
{
  DecOptions() : n_collapses(0){}

  CmdOption<bool>        decorate_name;
  CmdOption<float>       n_collapses;

  CmdOption<float>       AR;   // Aspect ratio
  CmdOption<float>       EL;   // Edge length
  CmdOption<float>       HD;   // Hausdorff distance
  CmdOption<bool>        IS;   // Independent Sets
  CmdOption<float>       ND;   // Normal deviation
  CmdOption<float>       NF;   // Normal flipping
  CmdOption<std::string> PM;   // Progressive Mesh
  CmdOption<float>       Q;    // Quadrics
  CmdOption<float>       R;    // Roundness

  template <typename T>
  bool init(CmdOption<T>& _o, const std::string& _val)
  {
    if (_val.empty())
    {
      _o.enable();
    }
    else
    {
      std::istringstream istr(_val);

      T v;

      if ((istr >> v).fail())
      {
        return false;
      }

      _o = v;
    }
    return true;
  }

  std::string& strip(std::string & line)
  {
    std::string::size_type pos = 0;

    pos = line.find_last_not_of(" \t");

    if (pos != 0 && pos != std::string::npos)
    {
      ++pos;

      line.erase( pos, line.length()-pos );
    }

    pos = line.find_first_not_of(" \t");

    if (pos!=0 && pos!=std::string::npos)
    {
      line.erase(0,pos);
    }

    return line;
  }
};

#endif // DEC_OPTIONS_H