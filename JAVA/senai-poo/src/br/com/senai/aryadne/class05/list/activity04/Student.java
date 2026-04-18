package br.com.senai.aryadne.class05.list.activity04;

public class Student {
    private String name;
    private int enroll;
    private double grade1, grade2;

    public Student(String name, int enroll, double grade1, double grade2) {
        setName(name);
        setEnroll(enroll);
        setGrades(grade1, grade2);
    }

    public void setName(String name) {
        if (name == null || name.trim().isEmpty()) throw new IllegalArgumentException("Invalid name.");
        this.name = name;
    }

    private void setEnroll(int enroll) {
        if (enroll < 0) throw new IllegalArgumentException("Enroll cannot be negative.");
        this.enroll = enroll;
    }

    public void setGrades(double grade1, double grade2) {
        if (grade1 < 0 || grade1 > 10 || grade2 < 0 || grade2 > 10) {
            throw new IllegalArgumentException("Grades must be between 0 and 10.");
        }
        this.grade1 = grade1;
        this.grade2 = grade2;
    }

    public double calculateAverage() {
        return (this.grade1 + this.grade2) / 2;
    }

    public void showStatus() {
        double avg = calculateAverage();
        System.out.println("Student: " + name);
        System.out.println("Average: " + avg);
        
        if (avg >= 7) {
            System.out.println("Status: APPROVED!");
        } else {
            System.out.println("Status: FAILED.");
        }
    }
}