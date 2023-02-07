#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "OptionActorNumberOfTagsOfTypeGroupCoordinationConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UOptionActorNumberOfTagsOfTypeGroupCoordinationConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TagID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxNumberOfTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreSelf;
    
    UOptionActorNumberOfTagsOfTypeGroupCoordinationConsideration();
};

