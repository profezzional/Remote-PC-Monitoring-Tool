package org.broadcast;

import java.net.InterfaceAddress;
import java.net.NetworkInterface;
import java.net.SocketException;
import java.util.Enumeration;

public class GetBroadcast {
    public static String getBroadcast() throws SocketException {
        System.setProperty("java.net.preferIPv4Stack", "true");

        for (Enumeration<NetworkInterface> interfaces = NetworkInterface.getNetworkInterfaces(); interfaces.hasMoreElements(); ) {
            NetworkInterface networkInterface = interfaces.nextElement();

            if (!networkInterface.isLoopback()) {
                for (InterfaceAddress addr : networkInterface.getInterfaceAddresses()) {
                    if (addr.getBroadcast() != null) {
                        return addr.getBroadcast().toString().substring(1);
                    }
                }
            }
        }

        return null;
    }
}