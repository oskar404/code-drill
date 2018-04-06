// Write a function that given a list of non negative integers, arranges them
// such that they form the largest possible u32. For example, given
// [50, 2, 1, 9], the largest formed u32 is 95021.

use std::env;
use std::cmp::Ordering;

fn main() {
    let mut numbers: Vec<u32> = Vec::new();
    let args: Vec<String> = env::args().collect();
    for s in &args[1..] {
        let n: u32 = match s.parse() {
            Ok(num) => { num },
            Err(_) => {
                eprintln!("error: Positive integer required: {}", s);
                return;
            },
        };
        numbers.push(n);
    }

    print!("{:?} -> ", numbers);
    numbers.sort_by(|a,b| sorter(a, b));
    numbers.iter().for_each(|i| print!("{}", i));
    println!("");
}

fn sorter(lhs: &u32, rhs: &u32) -> Ordering {
    let l: String = format!("{}{}", lhs, rhs);
    let r: String = format!("{}{}", rhs, lhs);
    r.cmp(&l)
}
