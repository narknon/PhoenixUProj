#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "OnExperienceLevelChangedDelegateDelegate.h"
#include "ExperienceManager.generated.h"

class UExperienceManager;

UCLASS(Blueprintable)
class UExperienceManager : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnExperienceLevelChangedDelegate m_onExperienceLevelChangedDelegate;
    
    UExperienceManager();
    UFUNCTION(BlueprintCallable)
    void SetLevelBounds(const int32 i_level, int32& o_startPoints, int32& o_endPoints);
    
    UFUNCTION(BlueprintCallable)
    void SetExperienceLevel(int32 NewLevel);
    
    UFUNCTION(BlueprintCallable)
    void OnSaveGameLoaded();
    
    UFUNCTION(BlueprintCallable)
    void OnNewGame(const UObject* Caller, const bool IsInIntro);
    
    UFUNCTION(BlueprintCallable)
    void OnGameToBeSaved();
    
    UFUNCTION(BlueprintCallable)
    int32 GetExperiencePoints();
    
    UFUNCTION(BlueprintCallable)
    int32 GetExperienceLevelStartPoints();
    
    UFUNCTION(BlueprintCallable)
    int32 GetExperienceLevelEndPoints();
    
    UFUNCTION(BlueprintCallable)
    int32 GetExperienceLevel();
    
    UFUNCTION(BlueprintCallable)
    static UExperienceManager* Get();
    
    UFUNCTION(BlueprintCallable)
    void GainExperienceByAction(const FString& ExperienceAction);
    
    UFUNCTION(BlueprintCallable)
    void AddExperience(const int32 Points, const FString& Source, const FString& source_detail);
    
};

