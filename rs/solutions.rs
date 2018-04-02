// Write a program that outputs all possibilities to put + or - or nothing
// between the numbers 1, 2, ..., 9 (in this order) such that the result is
// always 100. For example: 1 + 2 + 34 – 5 + 67 – 8 + 9 = 100.

const NUMBERS: [i32; 9] = [1,2,3,4,5,6,7,8,9];
const SUM: i32 = 100;

fn main() {
    // Initialize buffer with first value
    let mut buf: Vec<i32> = Vec::new();
    buf.push(NUMBERS[0]);
    recurse(&buf, 1);
}

fn recurse(buf: &Vec<i32>, idx: usize) {

    // Check if we have recursed to depth
    if idx >= NUMBERS.len() {
        let mut sum: i32 = 0;
        for i in buf.iter() {
            sum += i;
        }
        if sum == SUM {
            print_result(buf, sum);
        }
        return;
    }
    
    // Branch 1: Add number to previous
    {
        let mut buf = buf.clone(); // Local copy of buf
        buf.push(NUMBERS[idx]);
        recurse(&buf, idx+1);
    }
    
    // Branch 2: Subtract number from previous
    {
        let mut buf = buf.clone(); // Local copy of buf
        buf.push(-1*NUMBERS[idx]);
        recurse(&buf, idx+1);
    }

    // Branch 3: Concatenate number to previous
    let mut buf = buf.clone(); // Local copy of buf
    let prev: i32 = match buf.pop() { Some(v) => v, None => panic!("Logic ERR"), };
    let val = (10 * prev.abs() + NUMBERS[idx]) * if prev >= 0 { 1 } else { -1 };
    buf.push(val);
    recurse(&buf, idx+1);
}

fn print_result(buf: &Vec<i32>, sum: i32) {
    let mut first = true;
    for i in buf.iter() {
        if first {
            print!("{}", i);
        } else {
            print!(" {} {}", if *i < 0 { '-' } else { '+' } ,i.abs());            
        }
        first = false;
    }
    println!(" = {}", sum);
}

