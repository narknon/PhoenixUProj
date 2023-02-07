#pragma once
#include "CoreMinimal.h"
#include "EUtilityTrackedErrorType.h"
#include "OptionActorIsTrackedErrorReported_Base.h"
#include "OptionActorIsTrackedErrorReported.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UOptionActorIsTrackedErrorReported : public UOptionActorIsTrackedErrorReported_Base {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ErrorName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EUtilityTrackedErrorType ErrorType;
    
    UOptionActorIsTrackedErrorReported();
};

