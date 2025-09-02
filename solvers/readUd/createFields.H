const scalar pi(M_PI);
#include <cmath>
using namespace std;


Info<< "Reading physicalProperties\n" << endl;

IOdictionary physicalProperties
(
    IOobject
    (
        "physicalProperties",
        runTime.constant(),
        mesh,
        IOobject::MUST_READ_IF_MODIFIED,
        IOobject::NO_WRITE
    )
);

dimensionedScalar nu
(
    "nu",
    dimViscosity,
    physicalProperties.lookup("nu")
);

Info<< "Reading field U_d\n" << endl;
volVectorField U_d
(
   IOobject
   (
    "U_d",
    "0",   
    mesh,
    IOobject::MUST_READ,
    IOobject::AUTO_WRITE
   ),
   mesh//,
   //dimensionedVector("U_d", dimensionSet(0,1,-1,0,0,0,0), Foam::vector(0,0,0))
);		




    
 
