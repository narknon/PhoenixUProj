#pragma once
#include "CoreMinimal.h"
#include "ActorProvider.h"
#include "Object_NamedActor.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UObject_NamedActor : public UActorProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ActorName;
    
    UObject_NamedActor();
};

