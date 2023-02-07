#pragma once
#include "CoreMinimal.h"
#include "ActorProvider.h"
#include "Templates/SubclassOf.h"
#include "Object_SpawnActor.generated.h"

class AActor;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UObject_SpawnActor : public UActorProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> ActorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ActorName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AlignmentSocket;
    
    UObject_SpawnActor();
};

