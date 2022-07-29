class Exercise9_3 {
    public static void main(String[] args) {
        String fullPath = "c:\\jdk1.8\\work\\PathSeparateTest.java";
        String path = "";
        String fileName = "";
        int inx = fullPath.lastIndexOf("\\");
        path += fullPath.substring(0, inx);
        fileName += fullPath.substring(inx + 1);
        System.out.println("fullPath:" + fullPath);
        System.out.println("path:" + path);
        System.out.println("fileName:" + fileName);
    }
}
