!***********************************************************************
!*                   GNU Lesser General Public License
!*
!* This file is part of the GFDL Flexible Modeling System (FMS).
!*
!* FMS is free software: you can redistribute it and/or modify it under
!* the terms of the GNU Lesser General Public License as published by
!* the Free Software Foundation, either version 3 of the License, or (at
!* your option) any later version.
!*
!* FMS is distributed in the hope that it will be useful, but WITHOUT
!* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
!* FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
!* for more details.
!*
!* You should have received a copy of the GNU Lesser General Public
!* License along with FMS.  If not, see <http://www.gnu.org/licenses/>.
!***********************************************************************

   if (.not.module_is_initialized) call fms_io_init ( )

   if (.not.associated(Current_domain)) call mpp_error &
        (FATAL, 'set_domain not called')

 ! get the global data and write only on root pe
   call mpp_global_field ( Current_domain, data, gdata ) 
   if ( mpp_pe() == mpp_root_pe() ) write (unit) gdata

