// Write a function that computes the list of the first 100 Fibonacci numbers.
// By definition, the first two numbers in the Fibonacci sequence are 0 and 1,
// and each subsequent number is the sum of the previous two. As an example,
// here are the first 10 Fibonnaci numbers: 0, 1, 1, 2, 3, 5, 8, 13, 21, and 34.
use std::env;

fn main() {
    let size: usize;
    let args: Vec<String> = env::args().collect();
    match args.len() {
        1 => {
            eprintln!("error: Missing number of iterations!");
            return;
        },
        2 => {
            size = match args[1].parse() {
                Ok(n) => {
                    if n > 93 {
                        eprintln!("error: Input too large: {} (Integer overflow)", args[1]);
                        return
                    } else {
                        n
                    }
                },
                Err(_) => {
                    eprintln!("error: Positive integer required: {}", args[1]);
                    return;
                }
            }
        },
        _ => {
            eprintln!("error:Invalid number of arguments!");
            return;
        }
    }

    let result = fibonacci(size);
    for i in result {
        println!("{}", i);
    }
}

fn fibonacci(size: usize) -> Vec<i64> {
    let mut result: Vec<i64> = Vec::new();
    if size == 0 {
        return result;
    }
    result.push(0);
    if size == 1 {
        return result;
    }
    result.push(1);
    let mut i: usize = 2;
    while i < size {
        let next: i64 = result[i-2] + result[i-1];
        result.push(next);
        i += 1;
    }
    result
}

