#pragma once
#include "CoreMinimal.h"
#include "AblStartPositionGetter.h"
#include "AblStartPositionGetter_MatchAnimationPosition.generated.h"

class UMatchAnimationPositionCharacterGetter;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UAblStartPositionGetter_MatchAnimationPosition : public UAblStartPositionGetter {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMatchAnimationPositionCharacterGetter* SourceCharacterGetter;
    
public:
    UAblStartPositionGetter_MatchAnimationPosition();
};

