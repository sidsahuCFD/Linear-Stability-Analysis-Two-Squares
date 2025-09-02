// Solve the Momentum equation

MRF.correctBoundaryVelocity(U_d);

tmp<fvVectorMatrix> tU_dEqn
(
    fvm::ddt(U_d) + fvm::div(phi, U_d) + fvc::div(phi_d,U)
  + MRF.DDt(U_d)
  + (turbulence_d->divDevSigma(U_d))/Re
);

fvVectorMatrix& U_dEqn = tU_dEqn.ref();

U_dEqn.relax();

fvConstraints.constrain(U_dEqn);

if (pimple.momentumPredictor())
{
    solve(U_dEqn == -fvc::grad(p_d));

    fvConstraints.constrain(U_d);
}
