[33m0a0c7c9[m[33m ([m[1;36mHEAD -> [m[1;32mmain[m[33m)[m HEAD@{0}: commit: test 3
[33m912929b[m HEAD@{1}: commit: test 2
[33mca8773d[m[33m ([m[1;31morigin/main[m[33m, [m[1;31morigin/HEAD[m[33m)[m HEAD@{2}: commit: test number 1 for git usage :)
[33m1c1bf29[m HEAD@{3}: commit: Everything is great! Today I got all the way through pawn promotion. Next I will connect my CheckForEnd() function to the rest of my stuff.
[33m5fdc755[m HEAD@{4}: commit: I fixed the castling issue, it was literally two small tiny lines, I meant to assign tempCol1 and tempCol2 to the castle's column, but was assigning it to their row.
[33m4f46892[m HEAD@{5}: commit: Lots of changes have been made. Moving works great, en passant works. castling works except for black castles. I have no idea why, but after you castle with a black rook it becomes immobile. I don't know what is wrong, I should start by looking over my GetMoves() code. After I fix that I should keep testing to see what other bugs I have.
[33m8e2df0f[m HEAD@{6}: commit: I now have the white and black pawns. I am getting my images straight.
[33m2307d17[m HEAD@{7}: commit: just doing random stuff. waiting on madeleine's pictures
[33m511d5b2[m HEAD@{8}: commit: I am tired. welcome screen is good, maybe I will just figure out pawns and flipping that stuff later on...
[33mdf34e0d[m HEAD@{9}: commit: working on names and welcome screen
[33mabd96bf[m HEAD@{10}: commit: Everything that I have made in the back end works. Started work on the welcome screen. Plan is to have "Chess" on the top left side and player names and a way to toggle who is white on the right side. Exciting!
[33m8ed5513[m HEAD@{11}: commit: I think everything works!! I am not sure what to do next
[33mc02c2f8[m HEAD@{12}: commit: i think everything in getmoves() and checkkingsafety() works. next i must do extensive testing in all types of situations. then I can move on to who knows what
[33m5ee40e2[m HEAD@{13}: commit: continue fixing getmoves()
[33md6c1a2d[m HEAD@{14}: commit: so check king safety() was wrong lol. I wrote down an idea of how to fix it. I need to write it. the params are the same so I shouldn't need to change any code. If it works we need to go through and simplify our code, maybe rearranging if statements so that the whole process where I checkKingSafety() only happens once? Then I need to double check logic everywhere.
[33m2f9c136[m HEAD@{15}: commit: wrote CheckKingSafety(). Implemented it into bishop, castle, queen, and pawn. Need to do King and Knight. Need to read through ALL CODE IN PIECE'S CLASSES. I know it's a lot, but we have to do this because one small error could be impossible to track down later.
[33m29fdd11[m HEAD@{16}: commit: GetMoves() works for all pieces. Need to implement the CheckKingSafety() and add that to GetMoves().
[33m6502576[m HEAD@{17}: commit: GetMoves() works for all pieces. Need to implement the CheckKingSafety() and add that to GetMoves().
[33mb1232d4[m HEAD@{18}: commit: GetMoves() works for all pieces. Need to implement the CheckKingSafety() and add that to GetMoves().
[33m452e527[m HEAD@{19}: commit: n/a
[33mf0c2bf1[m HEAD@{20}: commit: n/a
[33m14403b4[m HEAD@{21}: commit: n/a
[33m450770e[m HEAD@{22}: commit: n/a
[33m60324be[m HEAD@{23}: commit: n/a
[33mb212d93[m HEAD@{24}: commit: n/a
[33me0fcc51[m HEAD@{25}: commit: update GetMoves() with changes from voice memo. Need to CAREFULLY go through every piece file and make sure the logic is all correct. Then, AND ONLY AFTER I HAVE CAREFULLY CHECKED MY LOGIC, can I proceed to considering how I will link my files so that I can implement the CheckKingSafety() function without circular inclusion.
[33me5fc736[m HEAD@{26}: commit: did GetMoves() for all pieces. Need to do the method to check if the movement puts the king in check and if so do not add that move to currMoves.
[33ma3d9f3f[m HEAD@{27}: commit: filled in basic stuff for GetMoves() for pawn, knight, and king. Not implementing en passant. Need to implement the check for if the move puts the king in check to every piece's GetMove(). Need to do the GetMove() for the pieces that require recursion.
[33m9ff85e7[m HEAD@{28}: commit: board has been constructed successfully.
[33mb823aea[m HEAD@{29}: commit: added class for all pieces and finished putting the pieces in the board initially
[33m91d6565[m HEAD@{30}: commit: added a board class, started on the pawn class and the empty space class.
[33m5ebe9d8[m HEAD@{31}: commit: added main file and cmake
[33m0a9b705[m HEAD@{32}: commit (initial): Initial commit
