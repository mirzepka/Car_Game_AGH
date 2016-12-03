package com.luugiathuy.apps.remotebluetooth;

import java.io.IOException;

public class RemoteBluetoothServer{
	
	public static void main(String[] args) throws IOException {
		Thread waitThread = new Thread(new WaitThread());
		waitThread.start();
		//System.out.println("KUUUUPA");
	//	Thread Sock = new Thread(new SocketServer());
		//Sock.start();
	}
}
