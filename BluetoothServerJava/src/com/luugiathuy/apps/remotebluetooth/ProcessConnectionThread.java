package com.luugiathuy.apps.remotebluetooth;
////MOJE do testu
import java.awt.EventQueue;
////
import java.awt.Robot;
import java.awt.event.KeyEvent;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.RandomAccessFile;
////////////////////////// SOCKEty:
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.concurrent.TimeUnit;
//////////////////////////

import javax.microedition.io.StreamConnection;
import java.lang.System;
public class ProcessConnectionThread implements Runnable{

	private StreamConnection mConnection;
	
	////////////////////////////////////////////////
	char tmp[]={0,0,0,0};
	////////////////////////////////////////////////
	// Constant that indicate command from devices
	private static final int EXIT_CMD = -1;
	private static final int KEY_RIGHT = 1;
	private static final int KEY_LEFT = 2;
//	MyFrame ramka=new MyFrame();
	//////////////////////////////SOCKETY:
	SocketServer serverS;
	private long  timeMeasure;
	
	private long period=20;
	//////////////////////////////
	public ProcessConnectionThread(StreamConnection connection) throws IOException
	{
		mConnection = connection;
		serverS=new SocketServer();
		timeMeasure=System.currentTimeMillis();
		/*EventQueue.invokeLater(new Runnable() {
			@Override
			public void run() {
				new MyFrame();
			}
		});*/
	}
	
	@Override
	public void run() {
		try {
		
			// prepare to receive data
			//OutputStream outputStream = mConnection.openOutputStream();
			InputStream inputStream = mConnection.openInputStream();
			char[] t=new char[2];
			System.out.println("waiting for input");
	        
	        while (true) {
	        	////////////////////////////////WYSYLANIE SOCKETA
	        	if((System.currentTimeMillis()-timeMeasure)>period){
	        	System.out.println("KUKUKU");
	        	
	        	serverS.start(tmp[0],tmp[1],tmp[2],tmp[3]);
	        	System.out.println("lafs;asfaf");
	        	timeMeasure=System.currentTimeMillis();
	        	}
	        	///////////////////////////////////////
	        //	outputStream.write(11);
	        byte[] bytes={0,0};
	        	int command = inputStream.read(bytes,0,2);
	        	//System.out.println(b[1]+"H");
	        	
	        	if (command == EXIT_CMD)
	        	{	
	        		System.out.println("finish process");
	        		break;
	        	}
	        	
	        	processCommand(bytes);
	    //    	char[] t=new char[2];
	        //	t[0]=69;t[1]=69;
	        	//SocketServer.wr.write(t,0,2);
        	}
        } catch (Exception e) {
    		e.printStackTrace();
    	}
	}
	
	
	/**
	 * Process the command from client
	 * @param command the command code
	 * @throws IOException 
	 */
	private void processCommand(byte[] command) throws IOException {
		//System.out.println((command&0x01ff)+" "+(0x0001ff&(command>>9))+" "+(0x0001ff&(command>>18)));
		////////////////SOCKETY
		tmp[0]=(char)((command[0]&0xf0)>>4);
		tmp[1]=(char)((command[0]&0x0f));
		tmp[2]=(char)((command[1]&0xf0)>>4);
		tmp[3]=(char)((command[1]&0x0f));;
		////////////////////SOCKETY
		
		System.out.println(Integer.toString(((tmp[0]<<4)|tmp[1])&0xff)+" "+Integer.toString(((tmp[2]<<4)|tmp[3])&0xff));
		
		/////////////////////
		 //inputStream = mConnection.openInputStream();
		////////////////////
		
		
	}
	private void sendData(){
		
	}
}
