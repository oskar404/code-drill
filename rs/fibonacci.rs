// Write a function that computes the list of the first 100 Fibonacci numbers.
// By definition, the first two numbers in the Fibonacci sequence are 0 and 1,
// and each subsequent number is the sum of the previous two. As an example,
// here are the first 10 Fibonnaci numbers: 0, 1, 1, 2, 3, 5, 8, 13, 21, and 34.

use std::env;

fn main() {

    let arg = env::args().nth(1).expect("error: Missing number of iterations!");
    let size: usize = arg.parse().expect("error: Positive integer required");
    if size > 93 {
        eprintln!("error: Input too large: {} (Integer overflow)", size);
        return;
    }
    let result = fibonacci(size);
    result.iter().for_each(|i| println!("{}", i));
}

fn fibonacci(size: usize) -> Vec<i64> {
    let mut result: Vec<i64> = Vec::new();
    match size {
        0 => { result },
        1 => { result.push(0); result },
        _ => {
            result.push(0);
            result.push(1);
            for i in 2..size {
                let next = result[i-2] + result[i-1];
                result.push(next);
            }
            result
        },
    }
}

