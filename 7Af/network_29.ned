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
            @display("p=214.30333,215.2");
        }
        toe: labfinalnode_29 {

            @display("p=53.8,52.006664");
        }
        toy: labfinalnode_29 {
            @display("p=172.16,49.316666");
        }
    connections:
        tic.out --> toc.in;
        toc.out --> toe.in;
        toe.out --> toy.in;
        toy.out --> tic.in;
}

