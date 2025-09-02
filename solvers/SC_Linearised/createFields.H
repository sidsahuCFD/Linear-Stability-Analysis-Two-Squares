#include <cmath>
using namespace std;


#include "createRDeltaT.H"

Info<< "Reading field p\n" << endl;
volScalarField p
(
    IOobject
    (
        "p",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);


Info<< "Reading field p_d\n" << endl;
volScalarField p_d
(
    IOobject
    (
        "p_d",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);


Info<< "Reading field U\n" << endl;
volVectorField U
(
    IOobject
    (
        "U",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

#include "createPhi.H"

Info<< "Reading field U_d\n" << endl;
volVectorField U_d
(
    IOobject
    (
        "U_d",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

const int N(U.size()*2);
const int N_p = 1;


Info<< "Reading/calculating face flux field phi_d \n" << endl;

surfaceScalarField phi_d
(
    IOobject
    (
        "phi_d",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    fvc::flux(U_d)
);

pressureReference pressureReference(p, pimple.dict());

mesh.schemes().setFluxRequired(p.name());
mesh.schemes().setFluxRequired(p_d.name()); //added


autoPtr<viscosityModel> viscosity(viscosityModel::New(mesh));

autoPtr<incompressible::momentumTransportModel> turbulence
(
    incompressible::momentumTransportModel::New(U, phi, viscosity)
);

autoPtr<incompressible::momentumTransportModel> turbulence_d //added
(
    incompressible::momentumTransportModel::New(U_d, phi_d, viscosity)
);


#include "createMRF.H"
#include "createFvModels.H"
#include "createFvConstraints.H"

   


   

