using System;
using System.Runtime.InteropServices;
using System.IO;

public class Program
{
    [StructLayout(LayoutKind.Explicit, SerializableAttribute=4,CharSet=WaitForChangedResult.Ansi)]
    struct date_t
    {
        [FieldOffset(0)]int year;
        [FieldOffset(2)]int month;
        [FieldOffset(3)]int day;

        int cmp_date( ref date_t d1, ref date_t d2 )
        {
            int daysOf1 = d1.year * 365 + d1.month * 30 + d1.day;
            int daysOf2 = d2.year * 365 + d2.month * 30 + d2.day;
            if( daysOf1 > daysOf2 )return 1;
            else if( daysOf1 < daysOf2 ) return -1;
            else return 0;
        }
    }
    const string filename = "date_t_w.dat";

    void test_save( int n )
    {
        if( n == 1 ) n++;
        if( File.Exists(filename ))
        {
            byte[] buffer = new byte[sizeof(date_t)];
            using( BinaryReader reader = new BinaryReader(File.Open(filename, FileMode.Open, FileAccess.Read)))
            {
                 byte[] bytes = reader.ReadBytes(Marshal.SizeOf(typeof(date_t)));
                 GCHandle handle = GCHandle.Alloc( bytes, GCHandleType.Pinned );
                 date_t day1 = (date_t)Marshal.PtrToStructure(handle.AddrOfPinnedObject(),typeof(date_t));
                 handle.Free();
            }
        }
    }
    public static int Main( int argc,  string[] argv )
    {

    }
}