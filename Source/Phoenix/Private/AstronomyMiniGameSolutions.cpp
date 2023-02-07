#include "AstronomyMiniGameSolutions.h"

class AActor;
class UDataTable;

void UAstronomyMiniGameSolutions::UpdateAstronomyMiniGameSolvedLerp(AActor* Actor, FAstronomyMiniGameSolveState SolveState) {
}

void UAstronomyMiniGameSolutions::UpdateAstronomyMiniGameSolve(AActor* Actor, FAstronomyMiniGameSolveState SolveState, bool& bIsSolved) {
}

void UAstronomyMiniGameSolutions::SetupAstronomyMiniGameSolve(AActor* Actor, FName PointOfInterest, const FAstronomyMiniGameSolutionEntry& Solution, FAstronomyMiniGameSolveState SolveState, const FString& Extra) {
}

void UAstronomyMiniGameSolutions::SetAstronomyMiniGameDone(AActor* Actor) {
}

void UAstronomyMiniGameSolutions::GetAstronomyMiniGameSolved(bool& bIsSolved) {
}

void UAstronomyMiniGameSolutions::GetAstronomyMiniGameSolution(UDataTable* SolutionTable, FName PointOfInterest, FAstronomyMiniGameSolutionEntry& Solution, bool& bValidSolution) {
}

void UAstronomyMiniGameSolutions::GetAstronomyMiniGameIsRunning(bool& bIsRunning) {
}

void UAstronomyMiniGameSolutions::GetAstronomyMiniGameInfo(AActor*& Telescope, FName& PointOfInterest, FAstronomyMiniGameSolutionEntry& Solution, FAstronomyMiniGameSolveState& SolveState, bool& bIsValid) {
}

float UAstronomyMiniGameSolutions::GetAstronomyMiniGameDistanceFromSolution() {
    return 0.0f;
}

void UAstronomyMiniGameSolutions::GetAstronomyMiniGameApproachRotationRollLerp(float& ApproachRotationRollLerp) {
}

void UAstronomyMiniGameSolutions::GetAstronomyMiniGameApproachRotationPitchYawLerp(float& ApproachRotationPitchYawLerp) {
}

void UAstronomyMiniGameSolutions::GetAstronomyMiniGameApproachLerp(float& ApproachLerp) {
}

void UAstronomyMiniGameSolutions::GetAstronomyMiniGameApproachFOVLerp(float& ApproachFOVLerp) {
}

void UAstronomyMiniGameSolutions::AstronomyMiniGameSolutionLogRow(FName PointOfInterestRowName, FAstronomyMiniGameSolutionEntry Solution, bool bWithRowHeader) {
}

void UAstronomyMiniGameSolutions::AstronomyMiniGameConstellationOverride(int32& ConstellationOverride) {
}

void UAstronomyMiniGameSolutions::AstronomyMiniGameAllowSolving(bool& bAllowSolving) {
}

UAstronomyMiniGameSolutions::UAstronomyMiniGameSolutions() {
}

