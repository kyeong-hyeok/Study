class MyTv2 {
    private boolean isPowerOn;
    private int channel;
    private int volume;
    private int prevchannel=0;
    final int MAX_VOLUME = 100;
    final int MIN_VOLUME = 0;
    final int MAX_CHANNEL = 100;
    final int MIN_CHANNEL = 1;
    void setChannel(int channel) {
        if(channel>MAX_CHANNEL || channel<MIN_CHANNEL)
            return;
        else {
            prevchannel = this.channel;
            this.channel = channel;
        }
    }
    void setVolume(int volume) {
        if(volume>MAX_VOLUME || volume<MIN_VOLUME)
            return;
        else this.volume=volume;
    }
    int getChannel() {
        return channel;
    }
    int getVolume() {
        return volume;
    }
    void gotoPrevChannel() {
        setChannel(prevchannel);
    }
}
class Exercise7_10 {
    public static void main(String args[]) {
        MyTv2 t = new MyTv2();
        t.setChannel(10);
        System.out.println("CH:"+t.getChannel());
        t.setVolume(20);
        System.out.println("VOL:"+t.getVolume());
        t.setChannel(10);
        System.out.println("CH:"+t.getChannel());
        t.setChannel(20);
        System.out.println("CH:"+t.getChannel());
        t.gotoPrevChannel();
        System.out.println("CH:"+t.getChannel());
        t.gotoPrevChannel();
        System.out.println("CH:"+t.getChannel());
    }
}
