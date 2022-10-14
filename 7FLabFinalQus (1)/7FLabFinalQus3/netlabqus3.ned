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

simple labqus3node24
{
    parameters:
        int start = default(3);
        int stop = default(10);
        double energy = default(1.8);

    gates:
        inout gate[];
}

network labqus3net24
{
    submodules:
        router24[15]: labqus3node24 {
            @display("p=80,124");
        }
    connections:
        router24[0].gate++ <--> router24[3].gate++;
        router24[3].gate++ <--> router24[2].gate++;
        router24[2].gate++ <--> router24[5].gate++;
        router24[5].gate++ <--> router24[4].gate++;
        router24[4].gate++ <--> router24[1].gate++;
        router24[1].gate++ <--> router24[2].gate++;
        router24[2].gate++ <--> router24[5].gate++;
        router24[5].gate++ <--> router24[6].gate++;
        router24[6].gate++ <--> router24[7].gate++;
        router24[7].gate++ <--> router24[8].gate++;
        router24[7].gate++ <--> router24[9].gate++;
        router24[7].gate++ <--> router24[10].gate++;
        router24[10].gate++ <--> router24[11].gate++;
        router24[11].gate++ <--> router24[12].gate++;
        router24[12].gate++ <--> router24[10].gate++;
}