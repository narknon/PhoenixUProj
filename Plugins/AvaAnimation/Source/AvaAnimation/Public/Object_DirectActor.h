#pragma once
#include "CoreMinimal.h"
#include "ActorProvider.h"
#include "Object_DirectActor.generated.h"

class AActor;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UObject_DirectActor : public UActorProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* Actor;
    
    UObject_DirectActor();
};

