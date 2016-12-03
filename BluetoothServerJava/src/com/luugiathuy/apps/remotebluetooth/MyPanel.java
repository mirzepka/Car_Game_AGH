package com.luugiathuy.apps.remotebluetooth;

import java.awt.*;

import javax.swing.JPanel;

public class MyPanel extends JPanel {
	public MyPanel() {
	//	setPreferredSize(new Dimension(400, 400));
	}

	@Override
	protected void paintComponent(Graphics g) {
		super.paintComponent(g);
		Graphics2D g2d = (Graphics2D) g;
System.out.println(Integer.toString(ProcessConnectionThread.x*20)+"KUPPPA");
		// prostokat
		//g2d.drawRect(10, 10, 380, 380);
		// kolo
int xx=ProcessConnectionThread.x;
int yy=ProcessConnectionThread.y;
g2d.drawOval(xx*2,yy*2,50,50);
	//	g2d.drawOval(ProcessConnectionThread.x, ProcessConnectionThread.y, ProcessConnectionThread.x+30, ProcessConnectionThread.y+30);
	}
}
