package com.luugiathuy.apps.remotebluetooth;

import javax.swing.JFrame;
import javax.swing.JPanel;

public class MyFrame extends JFrame {
	JPanel panel;
	public MyFrame() {
		super("Hello World");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setVisible(true);
		setSize(600, 600);
		panel = new MyPanel();

		add(panel);
	}
}
/*
import java.awt.EventQueue;

public class Test {
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			@Override
			public void run() {
				new MyFrame();
			}
		});
	}
}*/
