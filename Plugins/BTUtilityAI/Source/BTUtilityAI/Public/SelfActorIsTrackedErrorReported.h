#pragma once
#include "CoreMinimal.h"
#include "EUtilityTrackedErrorType.h"
#include "SelfActorIsTrackedErrorReported_Base.h"
#include "SelfActorIsTrackedErrorReported.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfActorIsTrackedErrorReported : public USelfActorIsTrackedErrorReported_Base {
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
    
    USelfActorIsTrackedErrorReported();
};

