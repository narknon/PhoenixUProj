#pragma once
#include "CoreMinimal.h"
#include "EKnowledgeAction.h"
#include "KnowledgeGainInfo.h"
#include "ModFilter_GainKnowledge_Base.h"
#include "ValueComparison.h"
#include "ModFilter_GainKnowledge_Custom.generated.h"

class UObject;

UCLASS(Blueprintable, EditInlineNew)
class UModFilter_GainKnowledge_Custom : public UModFilter_GainKnowledge_Base {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseCategoryFilter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CategoryFilter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseKnowledgeActionFilter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EKnowledgeAction> KnowledgeActionFilter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseCarrierSubtypeFilter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CarrierSubtypeFilter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseSubjectFilter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SubjectFilter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseValueFilter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FValueComparison ValueFilter;
    
public:
    UModFilter_GainKnowledge_Custom();
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool BlueprintPassesKnowledgeGainFilter(const UObject* InTargetObject, const FKnowledgeGainInfo& KnowledgeGainInfo) const;
    
};

