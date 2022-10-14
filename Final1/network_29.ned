//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//
simple labfinalnode_29
{
    gates:
        input in;
        output out;
}
network labnet
{
    @display("bgb=265,344");
    submodules:
        tic: labfinalnode_29 {
            @display("p=88,216");
        }
        toc: labfinalnode_29 {
            @display("p=219.68333,125.53333");
        }
        toe: labfinalnode_29 {

            @display("p=81,50");
        }
        toy: labfinalnode_29;
    connections:
        tic.out --> toc.in;
        toc.out --> toe.in;
        toe.out --> toy.in;
        toy.out --> tic.in;
}


