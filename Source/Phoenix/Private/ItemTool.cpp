#include "ItemTool.h"
#include "Components/StaticMeshComponent.h"

class ACharacter;
class UItemToolRecord;

UItemToolRecord* AItemTool::GetItemToolRecord() const {
    return NULL;
}

ACharacter* AItemTool::GetCharacter() const {
    return NULL;
}

AItemTool::AItemTool() {
    this->Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    this->AbleExecutionClass = NULL;
}

