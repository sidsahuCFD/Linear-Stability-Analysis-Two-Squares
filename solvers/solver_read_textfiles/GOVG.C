/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2011-2021 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Application
    icoFoam

Description
    Transient solver for incompressible, laminar flow of Newtonian fluids.

\*---------------------------------------------------------------------------*/

#include "fvCFD.H"
#include "pisoControl.H"
#include <Eigen/Dense>
#include "OFstream.H"
#include "volVectorField2VectorXd.H"
#include <fstream>
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{

    
    #include "setRootCaseLists.H"
    #include "createTime.H"
    #include "createMesh.H"
    #include "createFields.H"


    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

 
  
  const int N = 84253*2;
  const int N_p = 1;
  Eigen::VectorXd U_vec(N); 
 
   ifstream myfile;
   myfile.open("Eig1.txt");
   for (int i = 0; i < N; i++) {
       myfile >> U_vec(i);
   }
   	int k = 0;				
        forAll(U_d1, id)
        {	
    		U_d1[id].component(0) = U_vec(k);k++; 
    		U_d1[id].component(1)= U_vec(k);k++; 	 	  
        }
    
   
   ifstream myfile2;
   myfile2.open("Eig2.txt");
   for (int i = 0; i < N; i++) {
       myfile2 >> U_vec(i);
   }
   	k = 0;				
        forAll(U_d2, id)
        {	
    		U_d2[id].component(0) = U_vec(k);k++; 
    		U_d2[id].component(1)= U_vec(k);k++; 	 	  
        }
    
   ifstream myfile3;
   myfile3.open("Eig3.txt");
   for (int i = 0; i < N; i++) {
       myfile3 >> U_vec(i);
   }
   	k = 0;				
        forAll(U_d3, id)
        {	
    		U_d3[id].component(0) = U_vec(k);k++; 
    		U_d3[id].component(1)= U_vec(k);k++; 	 	  
        }
    
   ifstream myfile4;
   myfile4.open("Eig4.txt");
   for (int i = 0; i < N; i++) {
       myfile4 >> U_vec(i);
   }
   	k = 0;				
        forAll(U_d4, id)
        {	
    		U_d4[id].component(0) = U_vec(k);k++; 
    		U_d4[id].component(1)= U_vec(k);k++; 	 	  
        }
    
   ifstream myfile5;
   myfile5.open("Eig5.txt");
   for (int i = 0; i < N; i++) {
       myfile5 >> U_vec(i);
   }
   	k = 0;				
        forAll(U_d5, id)
        {	
    		U_d5[id].component(0) = U_vec(k);k++; 
    		U_d5[id].component(1)= U_vec(k);k++; 	 	  
        }
    
   ifstream myfile6;
   myfile6.open("Eig6.txt");
   for (int i = 0; i < N; i++) {
       myfile6 >> U_vec(i);
   }               
   
	k = 0;				
        forAll(U_d6, id)
        {	
    		U_d6[id].component(0) = U_vec(k);k++; 
    		U_d6[id].component(1)= U_vec(k);k++; 	 	  
        }
        
   ifstream myfile7;
   myfile7.open("Eig7.txt");
   for (int i = 0; i < N; i++) {
       myfile7 >> U_vec(i);
   }               
   
	k = 0;				
        forAll(U_d7, id)
        {	
    		U_d7[id].component(0) = U_vec(k);k++; 
    		U_d7[id].component(1)= U_vec(k);k++; 	 	  
        }
        
   ifstream myfile8;
   myfile8.open("Eig8.txt");
   for (int i = 0; i < N; i++) {
       myfile8 >> U_vec(i);
   }               
   
	k = 0;				
        forAll(U_d8, id)
        {	
    		U_d8[id].component(0) = U_vec(k);k++; 
    		U_d8[id].component(1)= U_vec(k);k++; 	 	  
        }
        
   ifstream myfile9;
   myfile9.open("Eig9.txt");
   for (int i = 0; i < N; i++) {
       myfile9 >> U_vec(i);
   }               
   
	k = 0;				
        forAll(U_d9, id)
        {	
    		U_d9[id].component(0) = U_vec(k);k++; 
    		U_d9[id].component(1)= U_vec(k);k++; 	 	  
        }
        
   ifstream myfile10;
   myfile10.open("Eig10.txt");
   for (int i = 0; i < N; i++) {
       myfile10 >> U_vec(i);
   }               
   
	k = 0;				
        forAll(U_d10, id)
        {	
    		U_d10[id].component(0) = U_vec(k);k++; 
    		U_d10[id].component(1)= U_vec(k);k++; 	 	  
        }                                
        
   ifstream myfile11;
   myfile11.open("U_D1.txt");
   for (int i = 0; i < N; i++) {
       myfile11 >> U_vec(i);
   }               
   
	k = 0;				
        forAll(U_dini, id)
        {	
    		U_dini[id].component(0) = U_vec(k);k++; 
    		U_dini[id].component(1)= U_vec(k);k++; 	 	  
        }        
    
U_d1.write();  
U_d2.write(); 
U_d3.write(); 
U_d4.write(); 
U_d5.write(); 
U_d6.write();
U_d7.write(); 
U_d8.write(); 
U_d9.write(); 
U_d10.write();  
U_dini.write();

Info<< "End\n" << endl;

    return 0;
}


// ************************************************************************* //
