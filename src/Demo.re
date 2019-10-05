// Js.log("Hello, BuckleScript and Reason!");

let linesRead = ref(0);

type readerState =
| ReadWorldDef
| ReadRoverDef
| ReadRoverCommands;

let nextReaderState = (rs: readerState):readerState => {
  switch(rs) {
    | ReadWorldDef => ReadRoverDef
    | ReadRoverDef => ReadRoverCommands
    | ReadRoverCommands => ReadRoverDef;
 }
};

type world = {
  width: int,
  height: int
};

type direction = N | E | S | W;
type instruction = L | R | M;

type rover = {
  x: int,
  y: int,
  direction: direction
};

type instructionSeq = array(instruction);

type parseResult = World(world) | Rover(rover) | InstructionSeq(instructionSeq);

let parseLine = (readerState, line):parseResult => {
  switch(readerState) {
    | ReadWorldDef => World({width: 6, height: 5})
    | ReadRoverDef => Rover({x: 1, y: 1, direction: N})
    | ReadRoverCommands => InstructionSeq([|L|]);
  }
};

let processInstructions = (w, r, i) => {
  Js.log("processing rover")
}

let myReaderState = ref(ReadWorldDef);
let myWorld = ref({width: 0, height: 0});
let currentRover = ref({x: 0, y:0, direction: N});

Readline.readline((line) => {
  switch(parseLine(myReaderState^, line)) {
    | World(w) => myWorld := w
    | Rover(r) => currentRover := r
    | InstructionSeq(instrSeq) => processInstructions(myWorld^, currentRover^, instrSeq)
  }
  myReaderState := nextReaderState(myReaderState^)
})

// Todo
// - [ ] parse world def
// - [ ] parse rover def
// - [ ] handle rover instruction
// - [ ] print final rover position after instruction seq
// - [ ] remember failed rovers
// - [ ] remember failed rovers
