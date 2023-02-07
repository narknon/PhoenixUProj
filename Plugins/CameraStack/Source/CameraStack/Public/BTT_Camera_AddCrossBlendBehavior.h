#pragma once
#include "CoreMinimal.h"
#include "BTT_Camera_Base.h"
#include "ECameraStackBehaviorSorting.h"
#include "Templates/SubclassOf.h"
#include "BTT_Camera_AddCrossBlendBehavior.generated.h"

class UCameraStackBehavior;
class UCameraStackBehaviorMultiCrossBlend;

UCLASS(Blueprintable)
class UBTT_Camera_AddCrossBlendBehavior : public UBTT_Camera_Base {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UCameraStackBehavior> BehaviorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendInDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendOutDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UCameraStackBehaviorMultiCrossBlend>> CrossBlendBehaviorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 GroupIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float weight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECameraStackBehaviorSorting CrossBlendSorting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FilterFlags;
    
    UBTT_Camera_AddCrossBlendBehavior();
};

