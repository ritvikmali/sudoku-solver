import requests
import json


class GenerateSudoku:
    def __init__(self):
        self.url = "https://sudoku-api.vercel.app/api/dosuku"
        self.output = ""
        self.start()

    def start(self):
        try:
            response = requests.get(self.url)
            if response.status_code == requests.codes["ok"]:
                response = response.json()
                if not self.check_response(response):
                    raise Exception("Error with API!")

                self.output += (
                    f"Difficulty: {response["newboard"]["grids"][0]["difficulty"]}\n\n"
                )

                self.output += (
                    "Code Input: "
                    + self.convert_board(response["newboard"]["grids"][0]["value"])
                    + "\n\n"
                )

                self.output += (
                    "Input: \n"
                    + self.format_sudoku(response["newboard"]["grids"][0]["value"])
                    + "\n\n"
                )

                self.output += (
                    "Solution: \n"
                    + self.format_sudoku(response["newboard"]["grids"][0]["solution"])
                    + "\n\n"
                )

                with open("IO.txt", "w") as file:
                    file.write(self.output)
        except Exception as e:
            print(f"Error: {str(e)}")

    def convert_board(self, board):
        return str(board).replace("[", "{").replace("]", "}")

    def check_response(self, response) -> bool:
        if not (
            "newboard" in response
            and "grids" in response["newboard"]
            and "value" in response["newboard"]["grids"][0]
            and "solution" in response["newboard"]["grids"][0]
        ):
            return False
        return True

    def format_sudoku(self, grid) -> str:
        output = ""
        for i in range(9):
            # Print the row
            row = ""
            for j in range(9):
                if grid[i][j] == 0:
                    row += ". "  # Use '.' for empty cells
                else:
                    row += str(grid[i][j]) + " "

                # Add a separator for the 3x3 blocks
                if (j + 1) % 3 == 0 and j < 8:
                    row += "| "

            output += row.strip() + "\n"  # Write the row to the file

            # Add a separator line for the 3x3 blocks
            if (i + 1) % 3 == 0 and i < 8:
                output += "---------------------\n"
        return output


GenerateSudoku()
