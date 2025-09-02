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

volVectorField U_dini
(
   IOobject
   (
    "U_dini",
    "0",
    mesh,
    IOobject::NO_READ,
    IOobject::AUTO_WRITE
   ),
   mesh,
   dimensionedVector("U_dini", dimensionSet(0,1,-1,0,0,0,0), Foam::vector(0,0,0))
);

volVectorField U_d1
(
   IOobject
   (
    "U_d1",
    "0",
    mesh,
    IOobject::NO_READ,
    IOobject::AUTO_WRITE
   ),
   mesh,
   dimensionedVector("U_d1", dimensionSet(0,1,-1,0,0,0,0), Foam::vector(0,0,0))
);

volVectorField U_d2
(
   IOobject
   (
    "U_d2",
    "0",
    mesh,
    IOobject::NO_READ,
    IOobject::AUTO_WRITE
   ),
   mesh,
   dimensionedVector("U_d2", dimensionSet(0,1,-1,0,0,0,0), Foam::vector(0,0,0))
);

volVectorField U_d3
(
   IOobject
   (
    "U_d3",
    "0",
    mesh,
    IOobject::NO_READ,
    IOobject::AUTO_WRITE
   ),
   mesh,
   dimensionedVector("U_d3", dimensionSet(0,1,-1,0,0,0,0), Foam::vector(0,0,0))
);

volVectorField U_d4
(
   IOobject
   (
    "U_d4",
    "0",
    mesh,
    IOobject::NO_READ,
    IOobject::AUTO_WRITE
   ),
   mesh,
   dimensionedVector("U_d4", dimensionSet(0,1,-1,0,0,0,0), Foam::vector(0,0,0))
);

volVectorField U_d5
(
   IOobject
   (
    "U_d5",
    "0",
    mesh,
    IOobject::NO_READ,
    IOobject::AUTO_WRITE
   ),
   mesh,
   dimensionedVector("U_d5", dimensionSet(0,1,-1,0,0,0,0), Foam::vector(0,0,0))
);

volVectorField U_d6
(
   IOobject
   (
    "U_d6",
    "0",
    mesh,
    IOobject::NO_READ,
    IOobject::AUTO_WRITE
   ),
   mesh,
   dimensionedVector("U_d6", dimensionSet(0,1,-1,0,0,0,0), Foam::vector(0,0,0))
);

volVectorField U_d7
(
   IOobject
   (
    "U_d7",
    "0",
    mesh,
    IOobject::NO_READ,
    IOobject::AUTO_WRITE
   ),
   mesh,
   dimensionedVector("U_d7", dimensionSet(0,1,-1,0,0,0,0), Foam::vector(0,0,0))
);

volVectorField U_d8
(
   IOobject
   (
    "U_d8",
    "0",
    mesh,
    IOobject::NO_READ,
    IOobject::AUTO_WRITE
   ),
   mesh,
   dimensionedVector("U_d8", dimensionSet(0,1,-1,0,0,0,0), Foam::vector(0,0,0))
);

volVectorField U_d9
(
   IOobject
   (
    "U_d9",
    "0",
    mesh,
    IOobject::NO_READ,
    IOobject::AUTO_WRITE
   ),
   mesh,
   dimensionedVector("U_d9", dimensionSet(0,1,-1,0,0,0,0), Foam::vector(0,0,0))
);

volVectorField U_d10
(
   IOobject
   (
    "U_d10",
    "0",
    mesh,
    IOobject::NO_READ,
    IOobject::AUTO_WRITE
   ),
   mesh,
   dimensionedVector("U_d10", dimensionSet(0,1,-1,0,0,0,0), Foam::vector(0,0,0))
);
 
