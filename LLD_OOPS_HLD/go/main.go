package main

import (
	"encoding/json"
	"fmt"
	"io"
	"net/http"
)
type Post struct {
	UserID int    `json:"userId"`
	ID     int    `json:"id"`
	Title  string `json:"title"`
	Body   string `json:"body"`
}
func main() {
	resp, err := http.Get("https://jsonplaceholder.typicode.com/posts/1")
	if err != nil {
		fmt.Println("Error:", err)
		return
	}
	defer resp.Body.Close()

	body, err := io.ReadAll(resp.Body)
	if err != nil {
		fmt.Println("Error reading body:", err)
		return
	}
	var data Post
	if err := json.Unmarshal(body, &data); err != nil {
		fmt.Println("Error parsing JSON:", err)
		return
	}

	fmt.Println("Parsed JSON:", data)
	pretty, _ := json.MarshalIndent(data, "", "  ")
	fmt.Println("Pretty JSON:\n", string(pretty))
}
