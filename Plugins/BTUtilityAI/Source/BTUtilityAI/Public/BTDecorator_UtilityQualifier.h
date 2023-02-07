#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "ConsiderationWithDisplayName.h"
#include "UtilityScoreProvider.h"
#include "BTDecorator_UtilityQualifier.generated.h"

class UQualifierOptions;
class UQualifierTask;

UCLASS(Blueprintable)
class BTUTILITYAI_API UBTDecorator_UtilityQualifier : public UBTDecorator, public IUtilityScoreProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ActionName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FConsiderationWithDisplayName> Considerations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UQualifierOptions* QualifierOptions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FConsiderationWithDisplayName> OptionConsiderations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UQualifierTask*> QualifierTasks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRestartTreeOnOptionChange;
    
    UBTDecorator_UtilityQualifier();
    
    // Fix for true pure virtual functions not being implemented
};

