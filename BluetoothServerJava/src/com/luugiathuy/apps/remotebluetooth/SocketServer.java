package com.luugiathuy.apps.remotebluetooth;

import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class SocketServer /*implements Runnable*/ {
	static ServerSocket serverSocket = null; 
	static Socket clientSocket = null;
	public static BufferedWriter wr;
	
	
	public SocketServer() throws IOException{
		serverSocket = new ServerSocket(4444); // 4447 is port number
		clientSocket = serverSocket.accept(); // blocks and listen until a connection is made. 
		wr = new BufferedWriter(new OutputStreamWriter(clientSocket.getOutputStream())); 
	System.out.println("WYJAZD KURDE");
	}
	 public   void  start(char xtmp1, char xtmp2,char ytmp1, char ytmp2) throws IOException{
		
		
        	wr.write(new char[]{xtmp1,xtmp2,ytmp1,ytmp2},0,4);
        	wr.flush();
        	//serverSocket.close();
        	//clientSocket.close();
        	//wr.close();
        	
		
	}
	/*@Override
	public void run() {
		
		
		try {
			start();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}*/
}
