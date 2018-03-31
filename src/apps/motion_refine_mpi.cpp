/***************************************************************************
 *
 * Authors: "Jasenko Zivanov & Sjors H.W. Scheres"
 * MRC Laboratory of Molecular Biology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * This complete copyright notice must be included in any revised version of the
 * source code. Additional authorship citations may be added, but existing
 * author citations must be preserved.
 ***************************************************************************/

#include <src/jaz/motion/motion_refiner_mpi.h>


int main(int argc, char *argv[])
{
    MotionRefinerMpi prm;

	try
    {
		prm.read(argc, argv);

		prm.initialise();

		MPI_Barrier(MPI_COMM_WORLD);

		prm.run();
    }

    catch (RelionError XE)
    {
    	if (prm.verb > 0)
    		//prm.usage();
        std::cerr << XE;
        MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
    }

    return 0;

}





