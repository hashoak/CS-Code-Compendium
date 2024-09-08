import java.io.*;

interface visit
{
    void regualarVisit();
    void periodicVisit();
}

class Doctor
{
    String name;
    int experience;
    int grade;
    Doctor(){;}
    Doctor(String name,int exp,int grd)
    {
        this.name=name;
        experience=exp;
        grade=grd;
    }
}

class Patient
{
    String name;
    int age;
    double height,weight;
    Patient(){;}
    Patient(String name,int age,double ht,double wt)
    {
        this.name=name;
        this.age=age;
        height=ht;
        weight=wt;
    }
}

class Consult
{
    Doctor d;
    Patient p;
    String problem,severity;
    int noOfMedi;
    String medications[];
    double charges;
    Consult(Doctor d,Patient p)
    {
        this.d=d;
        this.p=p;
    }
    void regularVisit(String reason)
    {
        if(reason=="Blood Test")
        {
            problem=reason;
            severity="Normal";
            noOfMedi=1;
            medications=new String[1];
            medications[0]="None";
            charges=750;
        }
        else if(reason=="Full Body Test")
        {
            problem=reason;
            severity="Normal";
            noOfMedi=1;
            medications=new String[1];
            medications[0]="None";
            charges=1500;
        }
    }
    void periodicVisit(String reason)
    {
        if(reason=="Accident")
        {
            problem=reason;
            severity="Medium";
            noOfMedi=2;
            medications=new String[2];
            medications[0]="Paracetamol";
            medications[1]="Levocitrezin";
            charges=2000;
        }
        else if(reason=="Trauma")
        {
            problem=reason;
            severity="High";
            noOfMedi=3;
            medications=new String[3];
            medications[0]="Paracetamol";
            medications[1]="Levocitrezin";
            medications[2]="AminolBenzene";
            charges=5000;
        }
    }
    void recordCase(String path)
    {
        try
        {
            FileOutputStream fout=new FileOutputStream(path);
            DataOutputStream dout=new DataOutputStream(fout);
            String s="Patient name: ";
            byte[] data=s.getBytes();
            dout.write(data);
            System.out.print(s);
            data=(d.name).getBytes();
            dout.write(data);
            System.out.print(d.name);
            s="\nDoctor name: ";
            data=s.getBytes();
            dout.write(data);
            System.out.print(s);
            data=(p.name).getBytes();
            dout.write(data);
            System.out.print(p.name);
            s="\nProblem: ";
            data=s.getBytes();
            dout.write(data);
            System.out.print(s);
            data=problem.getBytes();
            dout.write(data);
            System.out.print(problem);
            s="\nSeverity: ";
            data=s.getBytes();
            dout.write(data);
            System.out.print(s);
            data=severity.getBytes();
            dout.write(data);
            System.out.print(severity);
            s="\nMedications: ";
            data=s.getBytes();
            dout.write(data);
            System.out.print(s);
            for(int i=0;i<noOfMedi;i++)
            {
                data=(medications[i]+" ").getBytes();
                dout.write(data);
                System.out.print(medications[i]+" ");
            }
            s="\nCharge in Rs: ";
            data=s.getBytes();
            dout.write(data);
            System.out.print(s);
            dout.writeDouble((double)charges);
            System.out.print(charges);
            dout.close();
            fout.close();
        } catch(Exception e){;}
    }
}

class Main_1
{
    public static void main(String[] args)
    {
        Doctor d=new Doctor("Venkatesh",6,2);
        Patient p=new Patient("Ashok",18,175,65);
        Consult case1=new Consult(d,p);
        String path="text1.txt";
        case1.periodicVisit("Accident");
        case1.recordCase(path);
    }
}