// $Id$
//
// Class Torus
// ---------------
// VGM implementation for Root torus solid.
//
// Author: Ivana Hrivnacova; IPN Orsay

#ifndef ROOT_GM_TORUS_H
#define ROOT_GM_TORUS_H

#include <string>

#include "TGeoTorus.h"

#include "BaseVGM/solids/VTorus.h"

namespace RootGM {

  class Torus : public BaseVGM::VTorus
{
    public:
      Torus(const std::string& name, 
            double rin, double rout, double rax, double sphi, double dphi);
      Torus(TGeoTorus* torus);
      virtual ~Torus();

      // methods
      virtual std::string Name() const;
      virtual double InnerRadius() const;
      virtual double OuterRadius() const;
      virtual double AxialRadius() const;
      virtual double StartPhi() const;
      virtual double DeltaPhi() const;

    protected:
      Torus();
      Torus(const Torus& rhs);

    private:
      TGeoTorus* fTorus;
  };

}

#endif //ROOT_GM_TORUS_H
