#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AstronomyMiniGameSolutionEntry.h"
#include "AstronomyMiniGameSolveState.h"
#include "AstronomyMiniGameSolutions.generated.h"

class AActor;
class UDataTable;

UCLASS(Blueprintable)
class UAstronomyMiniGameSolutions : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UAstronomyMiniGameSolutions();
    UFUNCTION(BlueprintCallable)
    static void UpdateAstronomyMiniGameSolvedLerp(AActor* Actor, FAstronomyMiniGameSolveState SolveState);
    
    UFUNCTION(BlueprintCallable)
    static void UpdateAstronomyMiniGameSolve(AActor* Actor, FAstronomyMiniGameSolveState SolveState, bool& bIsSolved);
    
    UFUNCTION(BlueprintCallable)
    static void SetupAstronomyMiniGameSolve(AActor* Actor, FName PointOfInterest, const FAstronomyMiniGameSolutionEntry& Solution, FAstronomyMiniGameSolveState SolveState, const FString& Extra);
    
    UFUNCTION(BlueprintCallable)
    static void SetAstronomyMiniGameDone(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetAstronomyMiniGameSolved(bool& bIsSolved);
    
    UFUNCTION(BlueprintCallable)
    static void GetAstronomyMiniGameSolution(UDataTable* SolutionTable, FName PointOfInterest, FAstronomyMiniGameSolutionEntry& Solution, bool& bValidSolution);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetAstronomyMiniGameIsRunning(bool& bIsRunning);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetAstronomyMiniGameInfo(AActor*& Telescope, FName& PointOfInterest, FAstronomyMiniGameSolutionEntry& Solution, FAstronomyMiniGameSolveState& SolveState, bool& bIsValid);
    
    UFUNCTION(BlueprintCallable)
    static float GetAstronomyMiniGameDistanceFromSolution();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetAstronomyMiniGameApproachRotationRollLerp(float& ApproachRotationRollLerp);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetAstronomyMiniGameApproachRotationPitchYawLerp(float& ApproachRotationPitchYawLerp);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetAstronomyMiniGameApproachLerp(float& ApproachLerp);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetAstronomyMiniGameApproachFOVLerp(float& ApproachFOVLerp);
    
    UFUNCTION(BlueprintCallable)
    static void AstronomyMiniGameSolutionLogRow(FName PointOfInterestRowName, FAstronomyMiniGameSolutionEntry Solution, bool bWithRowHeader);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void AstronomyMiniGameConstellationOverride(int32& ConstellationOverride);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void AstronomyMiniGameAllowSolving(bool& bAllowSolving);
    
};

