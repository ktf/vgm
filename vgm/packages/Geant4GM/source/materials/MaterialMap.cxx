// $Id$
//
// Class MaterialMap
// ------------------
// The map between VGM and G4 materials.
//
// Author: Ivana Hrivnacova; IPN Orsay

#include "Geant4GM/materials/MaterialMap.h"

Geant4GM::MaterialMap*  Geant4GM::MaterialMap::fgInstance = 0;

//_____________________________________________________________________________
Geant4GM::MaterialMap* 
Geant4GM::MaterialMap::Instance()
{ 
// Singleton access function.
// ---

  if (!fgInstance) new MaterialMap();
  
  return fgInstance;
}  

//_____________________________________________________________________________
Geant4GM::MaterialMap::MaterialMap()
  : fG4Materials(),
    fVgmMaterials()
{
//  
  fgInstance = this;
}

//_____________________________________________________________________________
Geant4GM::MaterialMap::~MaterialMap() 
{
//
  fgInstance = 0;
}    

//
// public methods
//

//_____________________________________________________________________________
void  Geant4GM::MaterialMap::AddMaterial(VGM::IMaterial* iMaterial, 
                                         G4Material* g4Material)
{
// Adds the specified pair in the maps.
// ---

  fG4Materials[iMaterial] = g4Material;
  fVgmMaterials[g4Material] = iMaterial;
}  

//_____________________________________________________________________________
void  Geant4GM::MaterialMap::Print() const
{
// Prints all materials in  the maps.
// ---

  std::cout << "G4 Materials Map: " << std::endl; 

  int counter = 0;
  G4MaterialMapCIterator i;
  for (i = fG4Materials.begin(); i != fG4Materials.end(); i++) {
    VGM::IMaterial* iMaterial = (*i).first;
    G4Material* g4Material = (*i).second;
    
    std::cout << "   "
              << counter++ << "th entry:" 
	      << "  vgmMaterial " << iMaterial << " " << iMaterial->Name()
              << "  g4Material " << g4Material << " " << g4Material->GetName()
	      << std::endl;
  }
}  	       

//_____________________________________________________________________________
G4Material* 
Geant4GM::MaterialMap::GetMaterial(VGM::IMaterial* iMaterial) const
{
// Finds the G4 material corresponding to a specified VGM material.
// ---

  G4MaterialMapCIterator i = fG4Materials.find(iMaterial);
  if (i != fG4Materials.end()) 
    return (*i).second;
  else                 
    return 0;
}

//_____________________________________________________________________________
VGM::IMaterial* 
Geant4GM::MaterialMap::GetMaterial(G4Material* g4Material) const
{
// Finds the VGM material corresponding to a specified G4 material.
// ---

  VgmMaterialMapCIterator i = fVgmMaterials.find(g4Material);
  if (i != fVgmMaterials.end()) 
    return (*i).second;
  else                 
    return 0;
}