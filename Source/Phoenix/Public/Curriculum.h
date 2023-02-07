#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CurriculumKnowledgeRequirement.h"
#include "CurriculumRequirements_Updated.h"
#include "EDisciplineType.h"
#include "Curriculum.generated.h"

class UCurriculum;

UCLASS(Blueprintable)
class UCurriculum : public UObject {
    GENERATED_BODY()
public:
    UCurriculum();
    UFUNCTION(BlueprintCallable)
    bool SetCompleteYear_Updated(EDisciplineType Discipline, int32 Year);
    
    UFUNCTION(BlueprintCallable)
    bool SetCompleteAllTurnIns_Updated(EDisciplineType Discipline, int32 Year);
    
    UFUNCTION(BlueprintCallable)
    bool HasCompletedYear_Updated(EDisciplineType Discipline, int32 Year);
    
    UFUNCTION(BlueprintCallable)
    void GivePlayerRewardKnowledge_Updated(EDisciplineType Discipline, int32 Year);
    
    UFUNCTION(BlueprintCallable)
    void GivePlayerRewardItems_Updated(EDisciplineType Discipline, int32 Year);
    
    UFUNCTION(BlueprintCallable)
    bool GetUncompletedTurnIns_Updated(EDisciplineType Discipline, int32 Year, TArray<FCurriculumRequirements_Updated>& UncompletedTurnIns);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetMaxYear() const;
    
    UFUNCTION(BlueprintCallable)
    int32 GetHighestYearCompletedOverall_Updated();
    
    UFUNCTION(BlueprintCallable)
    int32 GetHighestYearCompleted_Updated(EDisciplineType Discipline);
    
    UFUNCTION(BlueprintCallable)
    int32 GetCurrentYear_Updated(EDisciplineType Discipline);
    
    UFUNCTION(BlueprintCallable)
    TArray<FCurriculumKnowledgeRequirement> GetApplicableKnowledgeCards(EDisciplineType Discipline, int32 Year);
    
    UFUNCTION(BlueprintCallable)
    static UCurriculum* Get();
    
};

