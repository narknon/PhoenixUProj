#pragma once
#include "CoreMinimal.h"
#include "RPGTriggerEffect_ActorDamaged.h"
#include "RPGTriggerEffect_ReflectDamageOnCursed.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class URPGTriggerEffect_ReflectDamageOnCursed : public URPGTriggerEffect_ActorDamaged {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool RequiresCursed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool OnPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DamageScale;
    
public:
    URPGTriggerEffect_ReflectDamageOnCursed();
};

