#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "SelfActorIsTrackedErrorReported_Base.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class USelfActorIsTrackedErrorReported_Base : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUnreported;
    
    USelfActorIsTrackedErrorReported_Base();
};

