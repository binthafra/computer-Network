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
simple final2node29
{
    parameters:
        int start = default(0);
        int stop = default(14);
        
        gates:
            inout gate[];
}

network labnet29
{
    submodules:
        router29[15]: final2node29;
        
    connections:
        router29[0].gate++ <--> router29[1].gate++;
        router29[0].gate++ <--> router29[2].gate++;
        router29[1].gate++ <--> router29[3].gate++;
        router29[0].gate++ <--> router29[4].gate++;
        router29[3].gate++ <--> router29[5].gate++;
        router29[3].gate++ <--> router29[6].gate++;
        router29[5].gate++ <--> router29[7].gate++;
        router29[9].gate++ <--> router29[8].gate++;
        router29[7].gate++ <--> router29[9].gate++;
        router29[6].gate++ <--> router29[8].gate++;
        router29[9].gate++ <--> router29[10].gate++;
        router29[10].gate++ <--> router29[11].gate++;
        router29[11].gate++ <--> router29[12].gate++;
        router29[12].gate++ <--> router29[14].gate++;
        router29[11].gate++ <--> router29[12].gate++;
        router29[12].gate++ <--> router29[14].gate++;
        router29[11].gate++ <--> router29[13].gate++;
        router29[7].gate++ <--> router29[13].gate++;
        
}