#include "pch.h"
#include "CppUnitTest.h"
#include "../../ChessProject/MetaData.h"
#include "../../ChessProject/ChessPiece.h"
#include "../../ChessProject/ChessBoard.h"
#include "../../ChessProject/ChessBoardTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ChessTest
{
	TEST_CLASS(ChessTest)
	{
	public:
		TEST_METHOD(ColorTest)
		{
			ChessColor black = ChessColor::Black;
			ChessColor white = ChessColor::White;
			Assert::AreEqual((int)ChessColor::Black, (int)black);
			Assert::AreEqual((int)ChessColor::White, (int)white);
			Assert::AreNotEqual((int)black, (int)white);
		}
		TEST_METHOD(StringColorTest)
		{
			std::string b = "B";
			std::string w = "W";
			Assert::AreNotEqual(b, w);
			
			std::string blackString = "Black";
			std::string whiteString = "White";

			Assert::AreNotEqual(blackString, whiteString);

			ChessColor white = ChessColor::White;
			ChessColor black = ChessColor::Black;

			std::string shortWhite = getShortNameOfChessColor(&white);
			Assert::AreEqual(w, shortWhite);
			std::string shortBlack = getShortNameOfChessColor(&black);
			Assert::AreEqual(b, shortBlack);
			
			std::string longWhite = getLongNameOfChessColor(&white);
			Assert::AreEqual(whiteString, longWhite);
			std::string longBlack = getLongNameOfChessColor(&black);
			Assert::AreEqual(blackString, longBlack);

			Assert::AreNotEqual(getLongNameOfChessColor(&black), getShortNameOfChessColor(&black));
			Assert::AreNotEqual(getLongNameOfChessColor(&white), getShortNameOfChessColor(&white));
		}
		TEST_METHOD(ChessTypeTest)
		{
			PieceType pawn = PieceType::Pawn;
			PieceType rook = PieceType::Rook;
			PieceType knight = PieceType::Knight;
			PieceType bishop = PieceType::Bishop;
			PieceType queen = PieceType::Queen;
			PieceType king = PieceType::King;
			
			std::string pawnLongString = "Pawn";
			std::string pawnShortString = "P";
			Assert::AreEqual(pawnLongString, getLongNameOfChessType(&pawn));
			Assert::AreEqual(pawnShortString, getShortNameOfChessType(&pawn));
			Assert::AreNotEqual(getShortNameOfChessType(&pawn), getLongNameOfChessType(&pawn));

			std::string rookLongString = "Rook";
			std::string rookShortString = "R";
			Assert::AreEqual(rookLongString, getLongNameOfChessType(&rook));
			Assert::AreEqual(rookShortString, getShortNameOfChessType(&rook));
			Assert::AreNotEqual(getShortNameOfChessType(&rook), getLongNameOfChessType(&rook));

			std::string knightLongString = "Knight";
			std::string knightShortString = "N";
			Assert::AreEqual(knightLongString, getLongNameOfChessType(&knight));
			Assert::AreEqual(knightShortString, getShortNameOfChessType(&knight));
			Assert::AreNotEqual(getShortNameOfChessType(&knight), getLongNameOfChessType(&knight));

			std::string bishopLongString = "Bishop";
			std::string bishopShortString = "B";
			Assert::AreEqual(bishopLongString, getLongNameOfChessType(&bishop));
			Assert::AreEqual(bishopShortString, getShortNameOfChessType(&bishop));
			Assert::AreNotEqual(getShortNameOfChessType(&bishop), getLongNameOfChessType(&bishop));

			std::string queenLongString = "Queen";
			std::string queenShortString = "Q";
			Assert::AreEqual(queenLongString, getLongNameOfChessType(&queen));
			Assert::AreEqual(queenShortString, getShortNameOfChessType(&queen));
			Assert::AreNotEqual(getShortNameOfChessType(&queen), getLongNameOfChessType(&queen));

			std::string kingLongString = "King";
			std::string kingShortString = "K";
			Assert::AreEqual(kingLongString, getLongNameOfChessType(&king));
			Assert::AreEqual(kingShortString, getShortNameOfChessType(&king));
			Assert::AreNotEqual(getShortNameOfChessType(&king), getLongNameOfChessType(&king));
		}
		TEST_METHOD(ChessTypeValueTest)
		{
			PieceType pawn = PieceType::Pawn;
			PieceType rook = PieceType::Rook;
			PieceType knight = PieceType::Knight;
			PieceType bishop = PieceType::Bishop;
			PieceType queen = PieceType::Queen;
			PieceType king = PieceType::King;
			
			Assert::AreEqual(USHRT_MAX, (int)getValueOfType(&king));
			Assert::AreEqual(9, (int)getValueOfType(&queen));
			Assert::AreEqual(5, (int)getValueOfType(&rook));
			Assert::AreEqual(3, (int)getValueOfType(&knight));
			Assert::AreEqual(3, (int)getValueOfType(&bishop));
			Assert::AreEqual(1, (int)getValueOfType(&pawn));
		}
		TEST_METHOD(ChessPieceTest)
		{
			ChessPiece wp(PieceType::Pawn, ChessColor::White);
			ChessPiece bp(PieceType::Pawn, ChessColor::Black);
			ChessPiece wr(PieceType::Rook, ChessColor::White);
			ChessPiece br(PieceType::Rook, ChessColor::Black);
			ChessPiece wk(PieceType::King, ChessColor::White);
			ChessPiece bk(PieceType::King, ChessColor::Black);
			ChessPiece wn(PieceType::Knight, ChessColor::White);
			ChessPiece bn(PieceType::Knight, ChessColor::Black);
			ChessPiece wb(PieceType::Bishop, ChessColor::White);
			ChessPiece bb(PieceType::Bishop, ChessColor::Black);
			ChessPiece wq(PieceType::Queen, ChessColor::White);
			ChessPiece bq(PieceType::Queen, ChessColor::Black);

			Assert::AreEqual((int)PieceType::Pawn,(int)*wp.getType());
			Assert::AreEqual((int)PieceType::Pawn, (int)*bp.getType());
			Assert::AreEqual((int)PieceType::Rook, (int)*wr.getType());
			Assert::AreEqual((int)PieceType::Rook, (int)*br.getType());
			Assert::AreEqual((int)PieceType::King, (int)*wk.getType());
			Assert::AreEqual((int)PieceType::King, (int)*bk.getType());
			Assert::AreEqual((int)PieceType::Knight, (int)*wn.getType());
			Assert::AreEqual((int)PieceType::Knight, (int)*bn.getType());
			Assert::AreEqual((int)PieceType::Bishop, (int)*wb.getType());
			Assert::AreEqual((int)PieceType::Bishop, (int)*bb.getType());
			Assert::AreEqual((int)PieceType::Queen, (int)*wq.getType());
			Assert::AreEqual((int)PieceType::Queen, (int)*bq.getType());

			Assert::AreEqual((int)ChessColor::White, (int)*wp.getColor());
			Assert::AreEqual((int)ChessColor::Black, (int)*bp.getColor());
			Assert::AreEqual((int)ChessColor::White, (int)*wr.getColor());
			Assert::AreEqual((int)ChessColor::Black, (int)*br.getColor());
			Assert::AreEqual((int)ChessColor::White, (int)*wk.getColor());
			Assert::AreEqual((int)ChessColor::Black, (int)*bk.getColor());
			Assert::AreEqual((int)ChessColor::White, (int)*wn.getColor());
			Assert::AreEqual((int)ChessColor::Black, (int)*bn.getColor());
			Assert::AreEqual((int)ChessColor::White, (int)*wb.getColor());
			Assert::AreEqual((int)ChessColor::Black, (int)*bb.getColor());
			Assert::AreEqual((int)ChessColor::White, (int)*wq.getColor());
			Assert::AreEqual((int)ChessColor::Black, (int)*bq.getColor());
		}
		TEST_METHOD(InvalidTypesAndColorForPieceTest)
		{
			PieceType noType = PieceType::NoType;
			ChessColor noColor = ChessColor::NoColor;
			PieceType rook = PieceType::Rook;
			ChessColor white = ChessColor::White;
			
			ChessPiece allInvalid = ChessPiece(noType, noColor);
			ChessPiece invalidType = ChessPiece(noType, white);
			ChessPiece invalidColor = ChessPiece(rook, noColor);
			ChessPiece empty = ChessPiece();
			ChessPiece valid = ChessPiece(rook, white);


			Assert::IsFalse(allInvalid.doesExist());
			Assert::IsFalse(invalidType.doesExist());
			Assert::IsFalse(invalidColor.doesExist());
			Assert::IsFalse(empty.doesExist());
			Assert::IsTrue(valid.doesExist());
		}
		TEST_METHOD(DefaultConstructorPieceTest)
		{
			ChessPiece p = ChessPiece();
			Assert::IsFalse(p.doesExist());
			Assert::AreEqual((int)ChessColor::NoColor, (int)*p.getColor());
			Assert::AreEqual((int)PieceType::NoType, (int)*p.getType());
		}
		TEST_METHOD(CordIsValidOnBoardTest)
		{
			ChessBoardTest board = ChessBoardTest();
			
			Assert::IsTrue(board.coordIsValid(0));
			Assert::IsTrue(board.coordIsValid(1));
			Assert::IsTrue(board.coordIsValid(2));
			Assert::IsTrue(board.coordIsValid(3));
			Assert::IsTrue(board.coordIsValid(4));
			Assert::IsTrue(board.coordIsValid(5));
			Assert::IsTrue(board.coordIsValid(6));
			Assert::IsTrue(board.coordIsValid(7));
			
			Assert::IsFalse(board.coordIsValid(-1));
			Assert::IsFalse(board.coordIsValid(8));		
		}
		TEST_METHOD(CordSetIsValidOnBoardTest)
		{
			ChessBoardTest board = ChessBoardTest();
			
			for (char file = 'a'; file <= 'h'; file++)
			{
				for (int rank = 1; rank <= 8; rank++)
				{
					Assert::IsTrue(board.coordSetIsValid(file, rank));
				}
			}
		}
		TEST_METHOD(BoardConvertingCoordsTest)
		{
			ChessBoardTest board = ChessBoardTest();
			Assert::AreEqual(0, board.file2Coords('a'));
			Assert::AreEqual(1, board.file2Coords('b'));
			Assert::AreEqual(2, board.file2Coords('c'));
			Assert::AreEqual(3, board.file2Coords('d'));
			Assert::AreEqual(4, board.file2Coords('e'));
			Assert::AreEqual(5, board.file2Coords('f'));
			Assert::AreEqual(6, board.file2Coords('g'));
			Assert::AreEqual(7, board.file2Coords('h'));

			Assert::AreEqual(-1, board.file2Coords('i'));
			Assert::AreEqual(-1, board.file2Coords('!'));
			Assert::AreEqual(-1, board.file2Coords(' '));
			
			Assert::AreEqual(0, board.rank2Coords(1));
			Assert::AreEqual(1, board.rank2Coords(2));
			Assert::AreEqual(2, board.rank2Coords(3));
			Assert::AreEqual(3, board.rank2Coords(4));
			Assert::AreEqual(4, board.rank2Coords(5));
			Assert::AreEqual(5, board.rank2Coords(6));
			Assert::AreEqual(6, board.rank2Coords(7));
			Assert::AreEqual(7, board.rank2Coords(8));

			Assert::AreEqual(-1, board.rank2Coords(9));
			Assert::AreEqual(-1, board.rank2Coords(0));
		}
		TEST_METHOD(PieceEqualOperatorTest)
		{
			ChessPiece wr = ChessPiece(PieceType::Rook, ChessColor::White);
			ChessPiece anotherWr = ChessPiece(PieceType::Rook, ChessColor::White);

			ChessPiece br = ChessPiece(PieceType::Rook, ChessColor::Black);
			ChessPiece anotherBr = ChessPiece(PieceType::Rook, ChessColor::Black);

			Assert::IsFalse(wr == br);
			Assert::IsFalse(wr == anotherBr);

			Assert::IsTrue(wr == anotherWr);
			Assert::IsTrue(br == anotherBr);

			//doesnt work for some reason
			//Assert::AreNotEqual(wr, br);
		}
		TEST_METHOD(BoardSetGetAtPositionTest)
		{
			ChessBoardTest board = ChessBoardTest();
			ChessPiece wr = ChessPiece(PieceType::Rook, ChessColor::White);
			board.setPieceAt(&wr, 'a', 1);
			ChessPiece* gottenPiece = board.getAtPosition('a', 1);
			Assert::IsTrue(wr == *gottenPiece);
			gottenPiece = board.getAtPosition('a', 2);
			Assert::IsFalse(wr == *gottenPiece);

		}
	};
}