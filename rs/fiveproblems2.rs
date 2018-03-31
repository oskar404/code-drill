// Write a function that combines two lists by alternatingly taking elements.
// For example: given the two lists [a, b, c] and [1, 2, 3], the function should
// return [a, 1, b, 2, c, 3].

fn main() {
    let v1 = ["A".to_string(), "B".to_string(), "C".to_string(), "D".to_string()];
    let v2 = ["1".to_string(), "2".to_string(), "3".to_string(), "4".to_string(),
              "XX".to_string(), "YY".to_string()];
    let result = alternate(&v1, &v2);
    print!("[");
    let mut first = true;
    for i in result {
        if ! first {
            print!(", ");
        }
        print!("{}", i);
        first = false;
    }
    println!("]");
}

fn alternate(v1: &[String], v2: &[String]) -> Vec<String> {
    let mut result: Vec<String> = Vec::new();
    let mut i = 0;
    while i < v1.len() || i < v2.len() {
        if i < v1.len() {
            result.push(v1[i].clone());
        }
        if i < v2.len() {
            result.push(v2[i].clone());
        }
        i += 1;
    }
    result
}

