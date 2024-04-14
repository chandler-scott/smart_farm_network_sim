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

package smart_farm.simulations;

import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import inet.node.contract.INetworkNode;
import inet.physicallayer.wireless.common.medium.RadioMedium;
import inet.visualizer.contract.IIntegratedVisualizer;
//
// Two instances (tic and toc) of Txc1 connected both ways.
// Tic and toc will pass messages to one another.
//
network farm_network
{
    parameters:
        int num_sensors = default(8);        
        @display("bgb=500,400;bgi=background/terrain;bgg=100,1,grey95");
        @figure[title](type=label; pos=0,-1; anchor=sw; color=darkblue);

    submodules:
        visualizer: <default(firstAvailableOrEmpty("IntegratedCanvasVisualizer"))> like IIntegratedVisualizer if typename != "" {
            @display("p=430,125");
        }
        configurator: Ipv4NetworkConfigurator {
            @display("p=430,200");
        }
        radioMedium: RadioMedium {
            @display("p=430,275");
        }
        server: <default("WirelessServerHost")> like INetworkNode {
            @display("p=300,200");
            @display("i=device/server");        
        }
        sensor[8]: <default("WirelessSensorHost")> like INetworkNode {
            @display("i=status/off");        
            
        }
}
